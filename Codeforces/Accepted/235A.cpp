#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int main()
{
    _
    ll n, ans, mx, x;
    scanf("%I64d", &n);
    if(n==1LL) printf("%I64d", 1ll);
    else if (n==2LL) printf("%I64d", 2ll);
    else if (n==3LL) printf("%I64d", (2*3ll));
    else
    {
            ans = x = n * (n-1);
            for (ll i = 1; i<n-1; i++)
                ans = max(ans,(x*i)/__gcd(x,i));
            x = (n-2) * (n-1);
            for (ll i = 1; i<n-2; i++)
                ans = max(ans,(x*i)/__gcd(x,i));
        printf("%I64d", ans);
    }

    return 0;
}
