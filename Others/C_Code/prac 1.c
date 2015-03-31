#include <stdio.h>

int main()
{
    int floor, numb2, ceiling, round;
    double numb, decimal;

    scanf("%lf", &numb);


    /*floor*/

    numb2 = numb;
    floor = numb2;

    if (numb >= 0) ;
    else if (numb2 == numb) ;
         else floor = numb2 - 1;


    /*ceiling*/

    ceiling = numb2;

    if (numb2 == numb) ;
    else if (numb > 0) ceiling = numb2 + 1;


    /*round*/

    if (numb >= 0)
    decimal = (numb - numb2);
    else decimal = (numb2 - numb);

    round = numb2;

    if (decimal == 0) ;
    else if (decimal == .5)
              {
                if (numb < 0) ;
                else if (numb >0) round++;
              }
         else if (decimal > .5)
              {
                if (numb < 0) round--;
                else if (numb >0) round++;
              }


    printf("For number: %lf\n Floor is      : %d\n Ceiling is    : %d\n Round is    : %d\n", numb, floor, ceiling, round);

    return 0;
}
