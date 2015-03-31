#include <stdio.h>

int gcd(int x, int y);

int main()
{
    int a, b;

    while (scanf("%d %d", &a, &b) == 2)
    {
        int res;
        if (a != 0 || b != 0)
        {
            res = gcd(a, b);
            if (res < 0) res = -res;
            printf("GCD = %d\n", res);
        }
        else printf("Undefined!\n");
    }
    return 0;
}

int gcd(int x, int y)
{
    if (y == 0) return x;
    return gcd (y, x % y);
}
