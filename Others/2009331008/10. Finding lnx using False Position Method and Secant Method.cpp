#include<stdio.h>
#include<math.h>


void false_position_method(double xl, double xu);
void secant_method(double xi_1, double xi);

main()
{
    false_position_method(0.5, 5.0);
    secant_method(0.5, 5.0);

}


void false_position_method(double xl, double xu)
{
    double xr, fu, fl,fr, test ;
    int iter=0;
    printf("Terms using False Position method: \n\n");
    printf("I       Xl      Xu         Xr\n\n");

    while(1)
    {
        iter++;
        printf("%d", iter);
        printf("%10lf", xl);
        printf("%10lf", xu);
        fu=log(xu)/0.434294481;
        fl=log(xl)/0.434294481;
        xr=xu -(fu*(xl-xu))/(fl-fu);
        printf("%10lf\n", xr);
        fr=log(xr)/0.434294481;
        test = fl*fr;
        if(test<0)
            xu=xr;
        else
            xl=xr;
        if(iter==3) break;
    }
    printf("\n\n\n");
}

void secant_method(double xi_1, double xi)
{
    double xr, fl, fu , fr;
    int iter=0;
    printf("Terms using Secant Method: \n\n");
    printf("I       X_i-1       Xi      X_i+1\n\n");
    while(1)
    {
        iter++;
        printf("%d ", iter);
        printf("%10lf", xi_1);
        printf("%10lf", xi);
        fu=log(xi)/0.434294481;
        fl=log(xi_1)/0.434294481;
        xr=xi -(fu*(xi_1-xi))/(fl-fu);
        printf("%10lf\n", xr);
        if(iter==2) break;
        xi_1=xi;
        xi=xr;
    }

}



