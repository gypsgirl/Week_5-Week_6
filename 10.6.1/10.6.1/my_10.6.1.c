#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define dx (M_PI/10.0)
#define Y 0.4
#define x_end M_PI
#define t_end 10.0
#define D 1.0
#define n_initial 1.0
#define dt (Y*dx*dx/D)

#define x_size (int)(ceil(x_end/dx))
#define t_size (int)(ceil(t_end/dt))

#define it 100000

int F(double t,double x)
{
    return 0;
}

double exact(double t,double x)
{
    return exp(-n_initial*n_initial*t)*sin(n_initial*x);
}

double error(double exact1,double approx)
{
    return (fabs(approx-exact1)/fabs(approx))*100;
}

void printAll(double u[t_size+1][x_size+1],FILE *fptr)
{
    double ex=0,err=0;
    FILE *ue;
    FILE *exe;
    FILE *ere;
    ue=fopen("u_explicit.txt","w");
    exe=fopen("ex_explicit.txt","w");
    ere=fopen("err_explicit.txt","w");

    for(int n=0;n<=t_size;n++)
    {
        for(int j=0;j<=x_size;j++)
        {
            ex=exact(n*dt,j*dx);
            //printf("%lf %lf\n\n",n*dt,j*dx);
            err=error(ex,u[n][j]);
            printf("u(%d)(%d): %3.20lf\t",n,j,u[n][j]);
            printf("Exact(%d): %3.20lf\t",j,ex);
            printf("Error(%d): %3.20lf\n",j,err);
            if(u[n][j]==0)
                fprintf(fptr,"%lf,%lf,%lf\n",u[n][j],ex,0.0);
            else
                fprintf(fptr,"%lf,%lf,%lf\n",u[n][j],ex,err);
            fprintf(ue,"%lf,",u[n][j]);
            fprintf(exe, "%lf,",ex);
            if(u[n][j]==0)
                fprintf(ere,"%lf,",0.0);
            else
                fprintf(ere, "%lf,",err);
        }
        fprintf(ue,"\n\n");
        fprintf(exe,"\n\n");
        fprintf(ere,"\n\n");

        printf("\n\n");
    }

    fclose(ue);
    fclose(exe);
    fclose(ere);
}

void printAll_1(double u[t_size+1][x_size+1],FILE *fptr1)
{
    double ex=0,err=0;
    FILE *ui;
    FILE *exi;
    FILE *eri;
    ui=fopen("u_implicit.txt","w");
    exi=fopen("ex_implicit.txt","w");
    eri=fopen("err_implicit.txt","w");

    for(int n=0;n<=t_size;n++)
    {
        for(int j=0;j<=x_size;j++)
        {
            ex=exact(n*dt,j*dx);
            //printf("%lf %lf\n\n",n*dt,j*dx);
            err=error(ex,u[n][j]);
            printf("u(%d)(%d): %3.20lf\t",n,j,u[n][j]);
            printf("Exact(%d): %3.20lf\t",j,ex);
            printf("Error(%d): %3.20lf\n",j,err);
            if(u[n][j]==0)
                fprintf(fptr1,"%lf,%lf,%lf\n",u[n][j],ex,0.0);
            else
                fprintf(fptr1,"%lf,%lf,%lf\n",u[n][j],ex,err);
            fprintf(ui,"%lf,",u[n][j]);
            fprintf(exi, "%lf,",ex);
            if(u[n][j]==0)
                fprintf(eri,"%lf,",0.0);
            else
                fprintf(eri, "%lf,",err);
        }
        fprintf(ui,"\n\n");
        fprintf(exi,"\n\n");
        fprintf(eri,"\n\n");

        printf("\n\n");
    }

    fclose(ui);
    fclose(exi);
    fclose(eri);
}

void printAll_2(double u_2[t_size+1][x_size+1],FILE *fptr2)
{
    double ex=0,err=0;
    FILE *ucn;
    FILE *excn;
    FILE *ercn;
    ucn=fopen("u_cranknicolson.txt","w");
    excn=fopen("ex_cranknicolson.txt","w");
    ercn=fopen("err_cranknicolson.txt","w");

    for(int n=0;n<=t_size;n++)
    {
        for(int j=0;j<=x_size;j++)
        {
            ex=exact(n*dt,j*dx);
            //printf("%lf %lf\n\n",n*dt,j*dx);
            err=error(ex,u_2[n][j]);
            printf("u(%d)(%d): %3.20lf\t",n,j,u_2[n][j]);
            printf("Exact(%d): %3.20lf\t",j,ex);
            printf("Error(%d): %3.20lf\n",j,err);
            if(u_2[n][j]==0)
                fprintf(fptr2,"%lf,%lf,%lf\n",u_2[n][j],ex,0.0);
            else
                fprintf(fptr2,"%lf,%lf,%lf\n",u_2[n][j],ex,err);
            fprintf(ucn,"%lf,",u_2[n][j]);
            fprintf(excn, "%lf,",ex);
            if(u_2[n][j]==0)
                fprintf(ercn,"%lf,",0.0);
            else
                fprintf(ercn, "%lf,",err);
        }
        fprintf(ucn,"\n\n");
        fprintf(excn,"\n\n");
        fprintf(ercn,"\n\n");

        printf("\n\n");
    }

    fclose(ucn);
    fclose(excn);
    fclose(ercn);
}

void printAll_3(double u_3[t_size+1][x_size+1],FILE *fptr3)
{
    double ex=0,err=0;
    FILE *ug;
    FILE *exg;
    FILE *erg;
    ug=fopen("u_gauss.txt","w");
    exg=fopen("ex_gauss.txt","w");
    erg=fopen("err_gauss.txt","w");

    for(int n=0;n<=t_size;n++)
    {
        for(int j=0;j<=x_size;j++)
        {
            ex=exact(n*dt,j*dx);
            //printf("%lf %lf\n\n",n*dt,j*dx);
            err=error(ex,u_3[n][j]);
            printf("u(%d)(%d): %3.20lf\t",n,j,u_3[n][j]);
            printf("Exact(%d): %3.20lf\t",j,ex);
            printf("Error(%d): %3.20lf\n",j,err);
            if(u_3[n][j]==0)
                fprintf(fptr3,"%lf,%lf,%lf\n",u_3[n][j],ex,0.0);
            else
                fprintf(fptr3,"%lf,%lf,%lf\n",u_3[n][j],ex,err);
            fprintf(ug,"%lf,",u_3[n][j]);
            fprintf(exg, "%lf,",ex);
            if(u_3[n][j]==0)
                fprintf(erg,"%lf,",0.0);
            else
                fprintf(erg, "%lf,",err);
        }
        fprintf(ug,"\n\n");
        fprintf(exg,"\n\n");
        fprintf(erg,"\n\n");

        printf("\n\n");
    }

    fclose(ug);
    fclose(exg);
    fclose(erg);
}

void zeroesU(double u[t_size+1][x_size+1])
{
    for(int i=0;i<=x_size;i++)
    {
        u[0][i]=sin(i*dx*n_initial);
    }
}

void boundaries(double u[t_size+1][x_size+1],int row)
{
    u[row][0]=0;
    u[row][x_size]=0;
}

void tridiagonal(double u_1[t_size+1][x_size+1])                  //n is changing
{
    int i,w,j,row;

    double alpha[x_size],g[x_size];

    double a=1.0+2.0*Y;
    double b=-Y;
    double c=-Y;

    alpha[1]=a;
    for(row=1;row<=t_size;row++)
    {
        g[1]=u_1[row-1][1];

        for(j=2;j<x_size;j++)
        {
            alpha[j]=a-c*b/alpha[j-1];
            g[j]=u_1[row-1][j]-b/alpha[j-1]*g[j-1];
        }

        u_1[row][x_size-1]=g[x_size-1]/alpha[x_size-1];

        for(w=x_size-2;w>0;w--)
        {
            u_1[row][w]=(g[w]-c*u_1[row][w+1])/alpha[w];
        }
    }

}

void fill(double u[t_size+1][x_size+1],int row)                   //Explicit
{
    for(int j=1;j<x_size;j++)
    {
        u[row][j]=u[row-1][j]+Y*(u[row-1][j-1]-2*u[row-1][j]+u[row-1][j+1])+dt*F(j*dt,j*dx);
    }
}

void fill_1(double u_1[t_size+1][x_size+1])                       //Implicit
{
    tridiagonal(u_1);
}

void fill_2(double u_2[t_size+1][x_size+1])                       //C-N
{
    int i,w,j,row;

    double alpha[x_size],g[x_size];

    double a=1.0+Y;
    double b=-Y/2.0;
    double c=-Y/2.0;

    alpha[1]=a;

    for(row=1;row<=t_size;row++)
    {
        g[1]=((Y/2)*u_2[row-1][0])+((1-Y)*u_2[row-1][1]+(Y/2)*u_2[row-1][2]);

        for(j=2;j<x_size;j++)
        {
            alpha[j]=a-c*b/alpha[j-1];
            g[j]=((Y/2)*u_2[row-1][j-1])+((1-Y)*u_2[row-1][j]+(Y/2)*u_2[row-1][j+1])-b/alpha[j-1]*g[j-1];
        }

        u_2[row][x_size-1]=g[x_size-1]/alpha[x_size-1];

        for(w=x_size-2;w>0;w--)
        {
            u_2[row][w]=(g[w]-c*u_2[row][w+1])/alpha[w];
        }
    }
}

void fill_3(double u_3[t_size+1][x_size+1])                       //Gauss
{
    int k,t,x,v,count=0;

    double a=1.0+2.0*Y;
    double b=-Y;
    double c=-Y;
    double ex,err,val[t_size][x_size],why=0,test=0,test1=0;

    FILE *log_1;
    log_1=fopen("log_1.txt","w");

    for(x=0;x<=x_size;x++)
    {
        val[0][x]=u_3[0][x];
    }

    for(t=1;t<=t_size;t++)
    {
        for(k=1;k<it;k++)
        {
            //printf("k: %d\n",k);
            test=0;
            test1=0;
            for(x=1;x<x_size;x++)
            {
                u_3[t][x]=(u_3[t-1][x]-b*u_3[t][x-1]-c*u_3[t][x+1])/a;
                //printf("u(%d)(%d): %lf ",t,x,u_3[t][x]);
                val[k][x]=u_3[t][x];
            }
            for(v=1;v<x_size;v++)
            {
                //printf("\nval(%d)(%d): %lf ",k-1,v,val[k-1][v]);
                why=fabs(u_3[t][v]-val[k-1][v]);
                //printf("why: %.9lf",why);
                if(why<0.00000001)
                {
                    test1++;
                    if(test1==x_size-1)
                    {
                        test=1;
                        break;
                    }
                }
            }

            //printf("\n");
            if(test==1)
            {
                if(t==t_size/2 & &x==x_size/2)
                {
                    printf("after break t=%d x=%d\n",t,x);
                    if(u_3[t][x]==0)
                    {
                        fprintf(log_1,"%lf",0.0);
                    }
                    else
                    {
                        ex=exact(t*dt,x*dx);
                        err=error(ex,u_3[t][x]);
                        fprintf(log_1,"%lf",log(err));
                    }
                }
                break;
            }
        }
    }
    fclose(log_1);
}

void Explicit()
{
    FILE *fptr;
    fptr=fopen("explicit.csv","w");
    //fprintf(fptr,"n,j,u[n][j],exact,error\n");
    //fptr=fopen("explicit.txt","w");

    printf("\nPart 1: Explicit\n\n");

    double u[t_size+1][x_size+1];

    zeroesU(u);

    for(int n=0;n<=t_size;n++)
    {
        boundaries(u,n);
    }
    for(int m=1;m<=t_size;m++)
    {
        fill(u,m);
    }

    printAll(u,fptr);

    if(Y<=0.5)
        printf("\nAlgorithm is unstable, so the results are too.\nLambda (D*dt)/(dx^2)=%lf\n",Y);
    else
        printf("Lambda: %lf\n",Y);

    fclose(fptr);
    printf("\n\n");
}

void Implicit()
{
    FILE *fptr1;
    fptr1=fopen("implicit.csv","w");
    //fprintf(fptr1,"n,j,u[n][j],exact,error\n");
    //fptr=fopen("implicit.txt","w");

    printf("\n\nPart 2: Implicit\n\n");

    double u_1[t_size+1][x_size+1];

    zeroesU(u_1);

    for(int m=0;m<=t_size;m++)
    {
        boundaries(u_1,m);
    }
    fill_1(u_1);

    printAll_1(u_1,fptr1);
    fclose(fptr1);
    printf("\n\n");
}

void CrankNicolson()
{
    FILE *fptr2;
    fptr2=fopen("cranknicolson.csv","w");
    //fprintf(fptr2,"n,j,u[n][j],exact,error\n");
    //fptr=fopen("cranknicolson.txt","w");

    printf("\nPart 3: Crank-Nicolson\n\n");

    double u_2[t_size+1][x_size+1];

    zeroesU(u_2);

    for(int n=0;n<=t_size;n++)
    {
        boundaries(u_2,n);
    }

    fill_2(u_2);

    printAll_2(u_2,fptr2);
    fclose(fptr2);
    printf("\n\n");
}

void Gauss()
{
    FILE *fptr3;
    fptr3=fopen("gauss.csv","w");
    //fprintf(fptr3,"n,j,u[n][j],exact,error\n");
    //fptr=fopen("gauss.txt","w");

    printf("\nPart 4: Gauss\n\n");

    double u_3[t_size+1][x_size+1];


    for(int k=0;k<=t_size;k++)
    {
        for(int i=0;i<=x_size;i++)
        {
            u_3[k][i]=sin(i*dx*n_initial);
        }
    }

    for(int n=0;n<=t_size;n++)
    {
        boundaries(u_3,n);
    }

    fill_3(u_3);

    printAll_3(u_3,fptr3);
    fclose(fptr3);
    printf("\n\n");
}

int main()
{

//-----------------------------------------Part 1: Explicit---------------------------------------------

    Explicit();

//-----------------------------------------Part 2: Implicit---------------------------------------------

    Implicit();

//-----------------------------------------Part 3: Crank-Nicolson---------------------------------------

    CrankNicolson();

//-----------------------------------------Part 4: Gauss------------------------------------------------

    Gauss();

    return 0;
}
