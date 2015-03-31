#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, a[50][10000], h[50], len[50];
    char ch;

    scanf("%d ", &n);

    for (i = 0; i < n; ++i)
    {
        h[i] = 0;
        ch = '0';
        for (j = 0; ch != '\n'; ++j)
        {
            scanf("%d", &a[i][j]);
            ch = getchar();
        }
        len[i] = j;

        for (j = 0; j < len[i]; ++j)
            if ( h[i] < a[i][j]) h[i] = a[i][j];
    }

    for (i = 0; i < n; ++i)
        printf("Case %d: %d\n", i+1, h[i]);
    return 0;
}
