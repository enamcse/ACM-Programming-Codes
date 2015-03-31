#include <stdio.h>

int main()
{
    int m1, m2, m, n1, n2, n, i, j, k, a[10][10], b[10][10], res[10][10], flag = 0;

    scanf("%d %d", &m1, &n1);

    for (i = 0; i < m1; ++i)
        for (j = 0; j < n1; ++j)
            scanf("%d", &a[i][j]);

    for (i = 0; i < m1; ++i)
    {
        for (j = 0; j < n1; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }


    scanf("%d %d", &m2, &n2);

    for (i = 0; i < m2; ++i)
        for (j = 0; j < n2; ++j)
            scanf("%d", &a[i][j]);

    for (i = 0; i < m1; ++i)
        for (j = 0; j < n2; ++j)
            res[i][j] = 0;
    printf("%d %d\n", n1, m2);
    if (n1 == m2)
    {
        for (i = 0; i < m1; ++i)
            for (j = 0; j < n2; ++j)
                for (k = 0; k < m1; ++k)
                    res[i][j] += (a[j][k] * b[k][i]);
        flag = 1;
    }
    else printf("Can't multiply!\n");

    if (flag == 1)
    {
        for (i = 0; i < m1; ++i)
        {
            for (j = 0; j < n2; ++j)
                printf("%d ", res[i][j] = 0);
            printf("\n");
        }

    }
}
