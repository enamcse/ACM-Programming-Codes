#include <stdio.h>

int main()
{
    int t, x1,x2,y1,y2,caseno=0,n,x,y;

    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n", ++caseno);
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf(" %d",&n);
        while(n--)
        {
            scanf("%d %d",&x,&y);
            if(x>x1&&x<x2&&y>y1&&y<y2) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
