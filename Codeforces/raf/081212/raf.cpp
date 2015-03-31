#include <stdio.h>

int main()
{
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);
    int n, m,i,p;

    while(scanf("%d %d",&n,&m)==2)
    {
        if(n>m)
        {
            for (i = 0; i<m; i++)
                printf("BG");
            p = n - m;
            for (i = 0; i<p; i++)
                printf("B");
        }
        else
        {
            for (i = 0; i<n; i++)
                printf("BG");
            p = m - n;
            for (i = 0; i<p; i++)
                printf("G");
        }
        printf("\n");
    }
    return 0;
}
