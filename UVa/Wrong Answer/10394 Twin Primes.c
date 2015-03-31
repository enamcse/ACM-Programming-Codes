#include <stdio.h>

int main()
{
    int n, count, flag, flag2, i, j, k;

    while (scanf("%d", &n) == 1)
    {
        count = 0;
        if (n == 0) printf("(%d,%c%d)\n", 0, ' ', 2);
        else if (n > 0)
        {
            for (i = 3; ; i += 2)
            {
                flag = 1;
                flag2 = 1;
                for (j = 2; j <= (n / 2); ++j)
                {
                    if (i % j == 0) flag = 0;
                }
                if (flag == 1)
                    for (k = 2; k <= (n / 2); ++k)
                    {
                        if ((i+2) % k == 0) flag2 = 0;
                    }
                if(flag == 1 && flag2 == 1) ++count;
                if (count == n) break;
            }
            printf("(%d,%c%d)\n", i, ' ', i + 2);
        }

    }
    return 0;
}
