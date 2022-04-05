#include<stdio.h>
#include<math.h>

#define pi 3.1416

double f(double x)
{
    return (x*sin(x));
}
int main()
{
    int n=200,i;
    double a=0,b=4*pi,x,h,odd=0,even=0,integral;
    h=(b-a)/n;
    printf("%lf %lf\n",a,f(a));
    for (i=1;i<n;i+=2)
    {
    	x=a+i*h;
        odd=odd+f(x);
        printf("%lf %lf\n",odd,f(odd));
    }
    for (i=2;i<n-1;i+=2)
    {
    	x=a+i*h;
        even=even+f(x);
        printf("%lf %lf\n",even,f(even));
    }
    printf("%lf %lf\n",b,f(b));
    return 0;
}
