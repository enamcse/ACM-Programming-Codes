#include <stdio.h>

int main()
{
    int n, rank[100][10], i, j, h;
    char page[10][100][100];

    scanf("%d", &n);

    for (i = 0; i < n; ++i)
        for (j = 0; j < 10; ++j)
        {
            scanf("%s", page[i][j]);
            scanf("%d", &rank[i][j]);
        }

    for (i = 0; i < n; ++i)
    {
        h = 0;
        printf("Case #%d:\n", i+1);
        for (j = 0; j < 10; ++j)
        	if (h < rank[i][j]) h = rank[i][j];

        for (j = 0; j < 10; ++j)
            if (h == rank[i][j]) printf("%s\n", page[i][j]);
    }
    return 0;
}
