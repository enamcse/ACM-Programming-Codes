
/* this assignment is for a general equation : " x*x-7x+2=0 "
   Name: Rajib Chandra Das
   Reg: 2009331008
*/


#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
main()
{
    double a, b, c, r1, r2;
    double mid, ans, error;

    a=1; b=-7; c=2;

    r1 = 4;  r2 = 10;

    int count=0;

    while(1)
    {
        mid = (r1+r2)/2;
        ans = a*mid*mid + b*mid + c;

        count++;

        error = ((6.7015621187-mid)/6.7015621187);  // True Value = 6.7015621187


        printf("%3d. True Fractional Relative Error: %10.15lf\n\n", count, error);

        if(ans<0)   r1=mid;
        else        r2=mid;

        if(count==50)
            break;
    }

    printf("Calculated answer is: %lf\n", mid);

}
