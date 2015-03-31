#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);//freopen("input.txt", "r+", stdin); accepted before
    freopen("output.txt", "w", stdout);// freopen("output.txt", "w+", stdout); accepted before
    int n, m,i,p;

    scanf("%d %d",&n,&m);

    if(n==m)
    {
        for (i = 0; i<n; i++)
            printf("BG");
    }
    else if(n>m)
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
            printf("GB");
        p = m - n;
        for (i = 0; i<p; i++)
            printf("G");
    }
    puts("");
    return 0;
    }
