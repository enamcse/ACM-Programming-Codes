#include <stdio.h>

int main()
{
    double a,b,c,n,i=0;
    a=0,b=1;
    printf("steps : ");
    scanf("%lf", &n);
    printf("fibonacci numbers are:\n ");
    printf("%.0lf\n%.0lf\n",a,b);
    while(i<n)
    {c=a+b;
    printf("%.0lf\n",c);
    a=b; b=c;
    i++;
    }
}
