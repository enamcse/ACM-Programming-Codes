#include <stdio.h>

int main()
{
    int i, j, t = 1, k;
    long n, lcm1, lcm2, prime, lcm, temp;

    scanf("%ld", &n);

    while (n != 0)
    {
        lcm = 1000000;
        for (i = 2; i <= n; ++i)
        {
            prime = 1;
            for (j = 2; j < i; ++j)
                if (i % j == 0) prime = 0;

            if (prime == 1 && n % i == 0)
            {
                lcm1 = i;
                lcm2 = n / lcm1;
                temp = lcm1 + lcm2;
                    if (temp < lcm) lcm = temp;
            }
        }

        if (lcm1 == n) printf("Case %d: %ld\n", t++, lcm1 + 1);
        else printf("Case %d: %ld\n", t++, lcm);
        scanf("%ld", &n);
    }
    return 0;
}
