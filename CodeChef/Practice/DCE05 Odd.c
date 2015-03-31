#include <stdio.h>

int main()
{
    int  i, j, t, n, k;

    scanf("%d", &t);

    for (i = 0; i < t; ++i)
    {
        scanf("%d", &n);
        k = 1;
        for (j = 0; n >= k; ++j)
        {
            	k *= 2;
        }

        k /= 2;
        printf("%d\n", k);
    }

    return 0;
}
