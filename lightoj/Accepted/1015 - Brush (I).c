#include <stdio.h>

int main()
{
    int t, caseno=0, sum, n,i,temp;

    scanf("%d",&t);
    while(t--)
    {
        sum = 0;
        scanf(" %d",&n);
        i=0;
        while(i<n)
        {
            scanf(" %d",&temp);
            if(temp<0) temp=0;
            sum+=temp;
            ++i;
        }
        printf("Case %d: %d\n", ++caseno, sum);
    }
    return 0;
}
