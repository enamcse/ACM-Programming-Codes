#include <stdio.h>

int main()
{
    int a, b, a_a, b_b, mod, quotient;

    while (scanf("%d %d", &a, &b) == 2)
    {
        if (a >= 0 && b >= 0)
        {
            quotient = a / b;
            mod = a % b;
        }
        else if (a <= 0 && b >= 0)
             {
                 a_a = -a;

                 if (b > a_a)
                 {
                     quotient = -((a_a / b)+1);
                     mod = b - (a_a % b);
                 }
                 else if (b < a_a)
                      {
                           quotient = -((a_a / b)+1);
                           mod = b - (a_a % b);
                      }
             }
             else if (a >= 0 && b < 0)
                  {
                      b_b = -b;
                      quotient = -a / b_b;
                      mod = a % b_b;
                  }
                  else if (a <=0 && b < 0)
                       {
                           a_a = -a;
                           b_b = -b;
                           quotient = a_a / b_b;
                           mod = a_a % b_b;
                       }

        printf("quotient for %d divided by %d is %d, where reminder is %d\n", a, b, quotient, mod);
    }
    return 0;
}
