#include <stdio.h>

int main()
{
    int i, j, m, n;
    int A[30][20], X[20], Y[30];

    printf("m = ? ");
    scanf("%d", &m);

    printf("n = ? ");
    scanf("%d", &n);

    printf("A = ?\n");

    for (i = 0; i < m; i++)
    {
        printf("Input the elements of row %d:\n", i + 1);
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    }


    printf("X = ? \n");

    for (i = 0; i < n; i++)
        scanf("%d", &X[i]);

    for (i = 0; i < m; i++)
        Y[i] = 0;

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            Y[i] += (A[i][j] * X[j]);

    printf("Y =\n");

    for (i = 0; i < m; i++)
        printf("%d ", Y[i]);

    return 0;
}
