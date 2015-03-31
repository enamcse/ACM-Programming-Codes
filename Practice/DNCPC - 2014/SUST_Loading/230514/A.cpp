#include <stdio.h>

using namespace std;

int main()
{
    int n, k , x, t,sum = 0, cas=1;
    scanf("%d", &t);
    while(t--)
    {
        sum=0;
        scanf("%d %d %d", &n, &k, &x);
        for (int i = 1; i<x; i++)
            sum+=i;
        for (int i = k+x; i<=n; i++)
            sum+=i;
        printf("Case %d: %d\n", cas++, sum);
    }

    return 0;
}
