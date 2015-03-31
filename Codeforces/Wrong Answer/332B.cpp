#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1000000
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

ll sum[sz], num[sz];

int main()
{
    _
    ll n, k, a,b;
    scanf("%lld %lld", &n, &k);
//cout<<"here";
    for (ll i = 0; i<n; i++)
    {
        scanf("%lld", &num[i]);
    }
    a = n-k+1;
    for (ll i = 0; i<a; i++)
    {
        for (ll j = 0; j<k; j++)
            sum[i]+=num[i+j];
    }

    ll best, best_ind=0, p, q, r;
    best = sum[0];
    for (ll i = 1; i<a; i++)
        if(sum[i]>best)
        {
            best = sum[i];
            best_ind = i;
        }
        p =-1;q=-1;
    for (ll i = 0; i<best_ind-k; i++)
    {
        if(sum[i]>p)
        {
            p = sum[i];
            q = i;
        }
    }
    for (ll i = best_ind+k; i<a; i++)
    {
        if(sum[i]>p)
        {
            p = sum[i];
            q = i;
        }
    }
    if(best_ind<q)
    {
        a = best_ind;
        b = q;
    }
    else
    {
        a = q;
        b = best_ind;
    }
    printf("%lld %lld\n", a+1,b+1);
    return 0;
}
