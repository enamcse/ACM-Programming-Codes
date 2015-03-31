#include <stdio.h>
#include <string.h>

#define mins min=a<b?a:b;
#define maxs max=a>b?a:b;

int main()
{
    int i, j, n = 1, t, min, max, a, b, flag, m;
    char ch[1000000], std;

    gets(ch);
    while(ch[0] != 0)
    {
        m = ch[0];
        printf("Case %d:\n", n++);
        scanf("%d", &t);
        for (i = 0; i < t; ++i)
        {
            flag = 1;
            scanf("%d %d", &a, &b);
            mins
            maxs

            std = ch[min];

            for (j = min; j <= max; ++j)
            	if(ch[j] != std) flag = 0;

            if(flag) printf("Yes\n");
            else printf("No\n");
        }
        gets(ch);
        gets(ch);
    }
    return 0;
}
