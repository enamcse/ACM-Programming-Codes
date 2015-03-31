#include <stdio.h>

int main()
{
    int hh[4], mm[4], count=1, n;

    scanf("%d ", &n);

    while(n--)
    {
        scanf(" %d:%d %d:%d",&hh[0],&mm[0],&hh[1],&mm[1]);
        scanf(" %d:%d %d:%d",&hh[2],&mm[2],&hh[3],&mm[3]);
        if((hh[1] < hh[2]))
            printf("Case %d: Hits Meeting\n", count++);
        else if((hh[1] == hh[2] && mm[1] < mm[2]))
            printf("Case %d: Hits Meeting\n", count++);
        else if ((hh[1] > hh[2]) && (hh[0] > hh[3]))
            printf("Case %d: Hits Meeting\n", count++);
        else if ((hh[1] > hh[2]) && (hh[0] == hh[3] && mm[0] > mm[3]))
            printf("Case %d: Hits Meeting\n", count++);
        else if ((hh[1] == hh[2] && mm[1] > mm[2]) && (hh[0] > hh[3]))
            printf("Case %d: Hits Meeting\n", count++);
        else if ((hh[1] == hh[2] && mm[1] > mm[2]) && (hh[0] == hh[3] && mm[0] > mm[3]))
            printf("Case %d: Hits Meeting\n", count++);
        else
            printf("Case %d: Mrs Meeting\n", count++);
    }

    return 0;
}
