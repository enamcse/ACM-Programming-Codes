#include <stdio.h>

int main()
{
    int t, n, p, q, w[100],i,sum,count,caseno=1;
    scanf("%d",&t);
    while(t--)
    {
        sum=count=0;
        scanf("%d %d %d",&n, &p, &q);
        for(i=0;i<n;i++)
        {
            scanf("%d",&w[i]);
        }

        for (i=0; count<p&&sum<q&&i<n;i++)
        {
            sum+=w[i];
            if(sum>q)
            {
                sum-=w[i];
                break;
            }
            count++;
        }
        printf("Case %d: %d\n",caseno++,count);
    }
    return 0;
}
