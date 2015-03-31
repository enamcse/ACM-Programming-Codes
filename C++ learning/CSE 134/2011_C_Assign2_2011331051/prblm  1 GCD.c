#include <stdio.h>

int main()
{
    int a, b, gcd = 1, i = 1, validity = 1, mod_a, mod_b;

    while (scanf("%d %d", &a, &b) == 2)
    {
        if (a == 0 && b == 0) validity = 0;
        else if (a == 0 || b == 0)
        {
            if (a < 0) gcd = -a;
            else if (b < 0) gcd = -b;
            else if (a > 0) gcd = a;
            else gcd = b;
        }
        else
        {
            if (a < 0) a = -a;
            if (b < 0) b = -b;

            for ( i = 1; i <= a && i <= b; i++)
            {
                if (i <= a) mod_a = a % i;
                if (i <= b) mod_b = b % i;
                if (mod_a == 0 && mod_b == 0) gcd = i;
            }
        }
        if (validity == 1) printf("GCD of these two numbers is: %d\n", gcd);
        else printf("Invalid input for determining GCD");
    }
    return 0;
}
