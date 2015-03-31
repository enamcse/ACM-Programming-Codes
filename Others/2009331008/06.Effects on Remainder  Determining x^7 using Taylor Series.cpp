
/*  Term = 3
    h=1 , 0.5, 0.25, 0.125,  .....upto step:10
*/


#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

main()
{
    double true_value, approximate_value, temp, x=1, error;
    int m=1;
    double h=1.0;

    printf("    h       True Value         Apprxmt_Value        remainder\n\n");
    int term=0;

    while(1)
    {
        term++;
        printf("    %lf", h);
        true_value=pow(x+h, 7.0);
        printf("       %lf", true_value);

        approximate_value=1+7*h+42*h*h/2;
        printf("        %lf", approximate_value);


        error=true_value-approximate_value;
        printf("        %10.10lf\n", error);
        temp=h/2;
        h-=temp;
        if(term==10)
            break;
    }
}
