#include<iostream>
#include<cmath>
#include<stdio.h>

using namespace std;

int factorial(int n)
{
    if(n<=1)
        return 1;
    else
        return n*factorial(n-1);
}
main()
{
    double true_value, approximate_value, temp, x=1, error;
    int m=1, h=1, term=0;

    printf("    M       True Value         Apprxmt_Value        Error\n\n");
    while(1)
    {
        printf("%4d", m);
        true_value=pow(2.0, m);
        printf("       %lf", true_value);

        approximate_value=pow(x, m)+m*pow(x, m-1)+m*(m-1)*pow(x, m-2)*h/2;

        printf("        %lf", approximate_value);
        m++;

        error=(true_value-approximate_value)/true_value*100;
        printf("        %15.8lf\n", error);

        if(m==11)
        break;

    }
}

