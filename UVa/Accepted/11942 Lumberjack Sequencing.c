#include <stdio.h>

int main()
{
    int i, j, n, a[15], flag;

    scanf("%d", &n);

    for (i = 0; i < n; ++i)
    {
        flag = 1;

        for (j = 0; j < 10; ++j)
            scanf(" %d", &a[j]);

        if (a[0] > a[1])
        {
            for (j = 1; j < 9; ++j)
                if (a[j] < a[j + 1]) flag = 0;
        }
        else if (a[0] < a[1])
        {
            for (j = 1; j < 9; ++j)
                if (a[j] > a[j + 1]) flag = 0;
        }
        else
            for (j = 1; j < 9; ++j)
            {
                if (a[j] > a[j + 1])
                {
                    for (j = j; j < 9; ++j)
                        if (a[j] < a[j + 1]) flag = 0;
                }
                else if (a[j] < a[j + 1])
                {
                    for (j = j; j < 9; ++j)
                        if (a[j] > a[j + 1]) flag = 0;
                }
            }
        if (i == 0) printf("Lumberjacks:\n");
        if (flag == 1) printf("Ordered\n");
        else printf("Unordered\n");
    }
    return 0;
}
