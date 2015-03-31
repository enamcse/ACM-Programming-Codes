#include <stdio.h>

int main()
{
    int i, t, n, mod, res;

    scanf("%ld", &t);

    for (i = 0; i < t; ++i)
    {
        scanf("%d", &n);

        res = n * 63;
        res += 7492;
        res *= 5;
        res -= 498;
        res /= 10;

        if (res < 0) res = -res;

        mod = res % 10;

        printf("%d\n", mod);
    }
    return 0;
}
