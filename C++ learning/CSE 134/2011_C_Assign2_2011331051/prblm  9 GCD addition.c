#include <stdio.h>

int gcd (int a, int b)
{
    int gcd = 1, i = 1, mod_a, mod_b;
    if (a == 0 && b == 0)
    {
        gcd = 0;
    }

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
    return gcd;
}

int main()
{
    int  m, n, o, i, gcd_add = 0;

    while (scanf("%d %d", &m, &n) == 2)
    {
        gcd_add = 0;
        o = m;

        for (o = m; o <= n; o++)
        {
            for (i = o; i <= n; i++)
                gcd_add = gcd_add + gcd(o, i);
        }

        printf("Sum of GCDs = %d\n", gcd_add);
    }

    return 0;
}
