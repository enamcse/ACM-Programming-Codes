    #include <stdio.h>
    int main()
    {
        long long t, n, m, i;
        scanf("%lld", &t);
        for(i=1;i<=t;i++)
        {
            scanf("%lld %lld", &n, &m);
            n>>=1;
            printf("Case %lld: %lld\n", i, n*m);
        }
        return 0;
    }
