#include<stdio.h>
#include<math.h>

double f(double x)
{
  return (x*x)+1;
}

int main()
{
  int n=200,i;
  double a=0,b=1,h,x,sum=0,in;
  
  h=fabs(b-a)/n;
  for(i=1;i<n;i++)
  {
    x=a+i*h;
    sum=sum+f(x);
  }
  in=h*(0.5)*((f(a)+f(b))+(2*sum));
  printf("\nThe integral is: %lf\n",in);
}
