#include<stdio.h>
#include<math.h>
#define N 300

double max(double df, double fd)
{
return fabs(df-fd);
}

double func(double x)
{
return ((x*x*x)+(4*x*x)-10);
}

double dfunc(double x)
{
return ((3*x*x)+(4*2*x));
}

double forw(double x0,double x1,double fx0,double fx1)
{
    return ((fx1-fx0)/(x1-x0));
}

double backw(double x1,double x0,double fx1,double fx0)
{
    return ((fx1-fx0)/(x1-x0));
}

double central(double x0,double x2,double fx0,double fx2)
{
    return ((fx2-fx0)/(x2-x0));
}

int main()
	{
	int n;
	n=300;
	double x[N+1],f[N+1],fd[N+1],df[N+1],h,m[N+1];
	x[0]=0;
	f[0]=func(x[0]);
	x[n]=10;
	h=((x[N]-x[0])/n);

	for(int i=1;i<N;i++)
	{
		x[i]=(x[i-1]+h);
		f[i]=func(x[i]);
	}
	f[n]=func(x[n]);

	fd[0]=forw(x[0],x[1],f[0],f[1]);
	df[0]=dfunc(x[0]);
	m[0]=max(df[0],fd[0]);

	printf("x: %lf f(x): %lf calcf(x): %lf df(x): %lf\n",x[0],f[0],fd[0],df[0]);

	for(int i=1;i<N;i++)
	{
		fd[i]=central(x[i-1],x[i+1],f[i-1],f[i+1]);
		df[i]=dfunc(x[i]);
		m[i]=max(df[i],fd[i]);
		printf("x: %lf f(x): %lf calcf(x): %lf df(x): %lf\n",x[i],f[i],fd[i],df[i]);
	}

	fd[N]=backw(x[N],x[N-1],f[N],f[N-1]);
	df[N]=dfunc(x[N]);
	m[N]=max(df[N],fd[N]);
	printf("x: %lf f(x): %lf calcf(x): %lf df(x): %lf\n",x[N],f[N],fd[N],df[N]);

	double temp=0;
	for(int i=0;i<=N;i++)
	{
		if(m[i]>temp)
		{
		temp=m[i];
		}
	}

	printf("Maximum difference: %lf\n",temp);
}
