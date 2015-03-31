#include <stdio.h>

int main()
{
    int i, x, y, p, q;

    scanf("%d %d", &x, &y);

    while(x != -1 && y != -1)
    {
        p = x - y;
        if (p<0) p =-p;
        q = 100 - p;

        if(p<=q) printf("%d\n",p);
        else printf("%d\n",q);

        scanf("%d %d", &x, &y);
    }


    return 0;
}
