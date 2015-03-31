#include<stdio.h>
#include<math.h>

double abs(double a)
{
    if(a<0) a=a*(-1);

    return a;
}

main()
{
    int i=0;
    double x=0, x_old, E_a, E_t;


    printf(" I           Xi            E_a(%%)       E_t(%%)\n\n");

    while(1)
    {
        printf("%2d", i);
        printf("        %lf", x);
        E_a = abs((x-x_old)/x*100);
        if(i==0) printf("           NULL");
        else printf("%15lf" , E_a);


        E_t = abs((0.56714329-x)/0.56714329*100);        // True value is: 0.56714329
        printf("%15lf\n" , E_t);
        i++;
        if(i==11) break;
        x_old=x;
        x=exp(x*(-1));
    }
}
