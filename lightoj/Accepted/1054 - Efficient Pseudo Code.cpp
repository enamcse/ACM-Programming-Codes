#include <stdio.h>

#define sz 50005
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

const ll mod = 1000000007;
ll bigmod(ll B,ll P,ll M)
{
    ll R=1;
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

int main()
{
#ifdef ENAM
    fread;
//    fwrite;
#endif // ENAM
    ll t, n, m, cas=1, k,i;
    ll ans;
    scanf("%lld", &t);

    while(t--)
    {
        scanf("%lld %lld", &n, &m);
        ans = 1;
        for (i = 2; i*i<=n; i++)
        {
            if(n%i==0)
            {
                k = 0;
                while(n%i==0) n/=i,k++;
                k*=m;
                ans = ans *(((bigmod(i,k+1,mod)-1+mod)%mod) * bigmod(i-1,mod-2,mod)%mod)%mod;
            }
        }
        if(n>1) ans = ans *(((bigmod(n,m+1,mod)-1+mod)%mod) * bigmod(n-1,mod-2,mod)%mod)%mod;

        printf("Case %lld: %lld\n", cas++, ans);
    }

    return 0;
}
