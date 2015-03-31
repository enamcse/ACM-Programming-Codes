#include <stdio.h>

int main()
{
    int caseno=1, n, l, h, w;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d %d", &l, &w, &h);
        if(l<21&&w<21&&h<21) printf("Case %d: good\n", caseno++);
        else printf("Case %d: bad\n", caseno++);
    }
    return 0;
}
