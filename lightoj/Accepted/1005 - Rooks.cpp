#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include<set>
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

ll rooks[sz][sz];
ll fact[30];


ll rec(ll n, ll k)
{
    if(k>n) return 0;
    ll &ret = rooks[n][k];
    if(ret != -1) return ret;
    if(k==0)
    {
        ret = 1;
        return ret;
    }
    ret = rec(n-1, k) + rec(n-1, k-1);
    return ret;
}

int main()
{
    ll t,cas=1,n, k, nCk;
    fact[0] = 1;
    scanf("%lld", &t);
    for (ll i = 1; i<30; i++)
        fact[i]=fact[i-1] * i;
    clr(rooks,-1);
    while(t--)
    {
        scanf("%lld %lld", &n, &k);

        if(n<k) printf("Case %lld: 0\n", cas++);
        else
        {
            if(n==k)
            {
                printf("Case %lld: %lld\n", cas++, fact[k]);
            }
            else
            {
                nCk = rec(n,k);
                printf("Case %lld: %lld\n", cas++, nCk*nCk*fact[k]);
            }
        }
    }
    return 0;
}
