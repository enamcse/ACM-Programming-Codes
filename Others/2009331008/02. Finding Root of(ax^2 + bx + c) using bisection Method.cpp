
/*Let us consider a general equation:  "a*x*x+b*x+c=0"  */

#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
main()
{
    double a, b, c, t;
    int count;
    while(1)
    {

        cout<<"a = : ";
        cin>>a;
        cout<<"b = : ";
        cin>>b;
        cout<<"c = : ";
        cin>>c;
        cout<<"Tolarance = : ";
        cin>>t;
        printf("Equation is: \n");
        printf("(%.0lf)*X*X + (%.0lf)*X + (%.0lf) = 0\n\n\n", a, b, c);

        double r1, r2, r, mid, ans, h;

        r=b/(2*a)*(-1);
        r1=-100000;
        r2=r;
        count=0;
        while(1)
        {
            mid=(r1 + r2)/2;
            ans = a*mid*mid + b*mid + c;
            count++;


            //printf("approximate value = %10.15lf\n", mid);
            h=r2-r1;
            if(h<t) break;

            if(ans>0)    r1=mid;
            else        r2=mid;

        }
        printf("First value is: %lf,      Found in Step no: %d\n" ,mid, count);


        r1=r;
        r2=+100000;
        count=0;
        while(1)
        {
            mid=(r1+r2)/2;
            ans = a*mid*mid + b*mid + c;
            count++;


            h=r2-r1;
            if(h<t) break;

            if(ans<0)   r1=mid;
            else        r2=mid;

        }

        printf("Second value is: %lf,      Found in Step no: %d\n\n\n" ,mid, count);



    }
}

