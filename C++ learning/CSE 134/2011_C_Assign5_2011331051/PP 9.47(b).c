#include <stdio.h>

int main()
{
    int i, j, l, m, n, k;
    double A[30][20], B[20][25], C[30][25];

    printf("k = ? ");
    scanf("%d", &k);

    printf("m = ? ");
    scanf("%d", &m);

    printf("A = ?\n");

    for (i = 0; i < k; i++)
    {
        printf("Input the elements of row %d:\n", i + 1);
        for (j = 0; j < m; j++)
            scanf("%lf", &A[i][j]);
    }

    printf("m = %d\n", m);

    printf("n = ? ");
    scanf("%d", &n);

    printf("B = ?\n");

    for (i = 0; i < m; i++)
    {
        printf("Input the elements of row %d:\n", i + 1);
        for (j = 0; j < n; j++)
            scanf("%lf", &B[i][j]);
    }

    for (i = 0; i < k; i++)
        for (j = 0; j < n; j++)
            C[i][j] = 0;

    for (i = 0; i < k; i++)
        for (j = 0; j < n; j++)
            for (l = 0; l < m; l++)
                C[i][j] += A[i][l] * B[l][j];

    printf("C =\n");

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < n; j++)
            printf("%3.2lf\t", C[i][j]);
        printf("\n");
    }

    return 0;
}
