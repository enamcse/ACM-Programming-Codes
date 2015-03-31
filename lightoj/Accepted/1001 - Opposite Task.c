#include <stdio.h>

int main()
{
    int a, n, i = 0;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%d", &a);
        if(a > 10) i = 10;
        else i = 0;
        printf("%d %d\n", i, a-i);
    }
    return 0;
}
/*
// efficient code
#include <stdio.h>

int main()
{
    int a, n, i;

    scanf("%d", &n);

    for (i=0; i<n; ++i)
    {
        scanf("%d", &a);
        if(a%2==0) printf("%d %d\n", a/2, a/2);
        else printf("%d %d\n", (a/2)+1, a/2);
    }
    return 0;
}
*/
