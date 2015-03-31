#include<stdio.h>
#include<math.h>
#define INF 99
FILE *fpt;

main()
{
    //fpt = fopen("sample.txt", "w+");
    double xl, xu, xr=0, tolerance , E_a;
    double fl, fu, fr, xr_old, iter=0, test, pp;
    double a, b, c;
    int flag=0;


    printf("Enter a: ");
    scanf("%lf",&a);
    printf("Enter b: ");
    scanf("%lf",&b);
    printf("Enter c: ");
    scanf("%lf",&c);
    printf("Enter Tolerance: ");
    scanf("%lf",&tolerance);

    xl = b/(2*a)*(-1);
    xu = INF;


    while(1)
    {
        fl = a*xl*xl + b*xl + c;
        fu = a*xu*xu + b*xu + c;

        xr_old = xr;
        xr=xu -(fu*(xl-xu))/(fl-fu);
        fr=a*xr*xr + b*xr + c;
        iter++;
        E_a=((xr-xr_old)/xr*100);
        if(E_a>pp)
        {
            flag=1;
            break;
        }
        printf("Approximate Error = %lf %%\n", E_a);
        if(E_a<tolerance) break;

        test = fl*fr;
        if(test<0)
            xu=xr;
        else
            xl=xr;
        pp=E_a;
    }
    if(flag==0)
        printf("Answer is : %lf         Found in Iteration: %lf\n", xr, iter);
    else
        printf("\n\nSorry, My Programme can not solve this equation Using False Position Method\n");

}
