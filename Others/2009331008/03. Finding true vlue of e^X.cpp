#include<iostream>
#include<stdio.h>

double factorial(double n)
{
    if(n<=1)
        return 1.0;
    else
        return n*factorial(n-1.0);
}

main()
{
    double i, j;
    double E_t, E_a;                            // Error From True value:  E_t  and  Error  from Approximate Value:  E_a
    double T = 1.648721270;                     // T = True value of e^0.5  = 1.648721270
    double A = 1.0, A_p = NULL;                 // A = Current Aproximate answer,  and  A_p =  Previous Approximate answer
    i=0;

    printf("Terms       Result      E_t(%%)          E_a(%%)\n\n");

    while(E_a>0.05)
    {

        E_t = ((T - A)/T)*100;
        E_a=((A - A_p)/A)*100;
        printf("%d   :     %lf     %lf     %10lf\n", int(i)+1, A, E_t, E_a);
        i++;
        j=1;

        for(int k=0;k<i;k++)
            j=j*0.5;

        j=j/factorial(i);
        A_p=A;
        A+=j;
    }
    printf("\n\nSo, My Calculated Answer is:  %10.15lf\n", A);
}
