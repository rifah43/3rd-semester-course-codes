#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPSILON 1e-9


double f(double x)
{
	return ((x)*(x)*(x)+ 4*(x)*(x) -10.0);
}


double df(double x)
{
	return (3*(x)*(x)+8*(x));
}


int main()
{
	int n=0;
	double a =1,b=2,c;
	while(1)
	{
		c=((a*f(b))-(b*f(a)))/(f(b)-f(a));
		n++;
		if(fabs(f(c))<EPSILON)
		{
			break;
		}
		else
		{
			a=b;
			b=c;
		}
	}
	printf("iteration: %d \n root: %lf\n",n,c);
	return 0;
}


