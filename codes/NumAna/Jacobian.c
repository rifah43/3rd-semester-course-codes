#include<stdio.h>
#include<math.h>

#define Eps 1e-9

double g1(double y, double z)
{
    return ((85-(3*y)+(2*z))/15);
}

double g2(double x, double z)
{
    return ((51-(2*x)-z)/10);
}

double g3(double x, double y)
{
    return ((5+(2*y)-x)/8);
}

int main()
{
    double xNew, yNew, zNew,x=0,y=0,z=0;
    int itr=0;
    while(1)
    {
        itr++;
        xNew=g1(y,z);
        yNew=g2(x,z);
        zNew=g3(x,y);
        
        if(fabs(x-xNew)<Eps && fabs(y-yNew)<Eps && fabs(z-zNew)<Eps)
        {
            break;
        }
        x=xNew;
        y=yNew;
        z=zNew;
    }
    printf("Roots: %lf\t %lf\t %lf\n",x,y,z);
    printf("Iteration: %d\n",itr);
    return 0;
}
