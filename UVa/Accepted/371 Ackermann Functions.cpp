#include <stdio.h>
#define ll long long
ll cycle_length (ll n);

int main()
{
    ll i, j, k, large, n, p, q, pos;

    while(scanf("%lld %lld", &i, &j) == 2&&(i||j))
    {
        q = i > j ? i : j;
        p = i < j ? i : j;
        large = 0;
        pos=p;
        for (k = p; k <= q; k++)
        {
            n = cycle_length(k);
            if (n > large)
            {
                large = n;
                pos=k;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", p, q,pos, large);
    }
    return 0;
}

ll cycle_length(ll x)
{
    ll i=0;
    if (x % 2 == 1) x = (3 * x + 1);
        else (x >>= 1);
    for (i = 1; x != 1; ++i)
    {
        if (x % 2 == 1) x = (3 * x + 1);
        else (x >>= 1);
    }
    return i;
}
