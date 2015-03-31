#include <stdio.h>

int cycle_length (int n);

int main()
{
    int i, j, k, large, n, p, q;

    while(scanf("%d %d", &i, &j) == 2)
    {
        if (i > 0 && j > 0)
        {
            q = i > j ? i : j;
            p = i < j ? i : j;
            large = 0;
            for (k = p; k <= q; k++)
            {
                n = cycle_length(k);
                if (n > large) large = n;
            }
            printf("%d %d %d\n", i, j, large);
        }
    }
    return 0;
}

int cycle_length(int x)
{
    int i;
    if(x != 1)
    {
        for (i = 1; x != 1; ++i)
        {
            if (x % 2 == 1) x = (3 * x + 1);
            else x = x / 2;
        }
    }
    else i = 1;
    return i;
}
