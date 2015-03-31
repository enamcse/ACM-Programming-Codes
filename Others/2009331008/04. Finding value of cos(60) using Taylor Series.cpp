#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
#define PI 2*acos(0)

int factorial(int n)
{
    if(n<=1)
        return 1;
    else
        return n*factorial(n-1);
}

main()
{
    double E_t, approximate_value=0, h, temp, true_value=0.5;

    int n=0, term=0, sum;
    int f1=1, f2=1;
    h=PI/12;
    printf("Order,n     Fn(x)             F(PI/3)             E_t\n\n");
    while(1)
    {
        printf("%3d", term);

        if(f1==1&&f2==1)
        {
            printf("         cosx");
            temp = cos(PI/4);
            f1=2;
            f2=2;
        }
        else if(f1==2&&f2==1)
        {
            printf("         sinx");
            temp = sin(PI/4);
            f2=1;
            f1=1;
        }
        else if(f1==1&&f2==2)
        {
            printf("        -cosx");
            temp = -cos(PI/4);
            f1=2;
            f2=1;
        }
        else if(f1==2&&f2==2)
        {
            printf("        -sinx");
            temp=-sin(PI/4);
            f1=1;
            f2=2;
        }
        //cout<<pow(h, n)<<endl;

        temp=temp*pow(h, n);
        temp=temp/factorial(term);
        approximate_value+=temp;
        printf("%23.10lf",approximate_value);
        E_t=((true_value-approximate_value)/true_value)*100;
        printf("%17.10lf\n", E_t);

        term++;
        n++;
        if(term==10)
            break;
    }
}
