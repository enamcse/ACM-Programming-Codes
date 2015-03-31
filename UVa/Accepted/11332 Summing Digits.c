#include <stdio.h>

int main()
{
    int i, l, m, sum, n;

    while(scanf("%d", &n) == 1)
    {
        if (n <= 0) break;
        l = n;
        sum = 0;

        for (i = 1; i <= 10; i++)
        {
            m = l % 10;
            l = l / 10;
            sum += m;
        }

        if (sum > 9)
        {
            l = sum;
            sum = 0;

            for (i = 1; i <= 2; i++)
            {
                m = l % 10;
                l = l / 10;
                sum += m;
            }
        }

        if (sum > 9)
        {
            l = sum;
            sum = 0;

            for (i = 1; i <= 2; i++)
            {
                m = l % 10;
                l = l / 10;
                sum += m;
            }
        }

        printf("%d\n", sum);
    }
    return 0;
}
