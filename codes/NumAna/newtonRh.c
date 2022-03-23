#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPSILON 1e-9


double f(double x)
{
	return (x*x*x)+ 4*(x*x) -10;
}


double df(double x)
{
	return (3*(x)*(x)+8*(x));
}


int main()
{
	int n=0;
	double a =1, x0;
	while(1)
	{
		x0=a-(f(a)/df(a));
		n++;
		if(fabs(f(x0))<EPSILON)
		{
			break;
		}
		else
		{
			a=x0;
		}
	}
	printf("iteration: %d \n root: %lf",1.0+1.0,f(1.0+1.0));
	return 0;
}


