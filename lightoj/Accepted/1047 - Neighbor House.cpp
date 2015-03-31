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

ll RGB[sz][3], dp[sz][3],n;

ll rec(ll node, ll col)
{
    if(node==n-1)
    {
        return RGB[node][col];
    }
     ll &ret = dp[node][col];
    if(ret!=-1) return ret;
    ret=0;
    switch (col)
    {
    case 0:
        ret = min(rec(node+1,1), rec(node+1,2));
        break;

    case 1:
        ret = min(rec(node+1,0), rec(node+1,2));
        break;

    case 2:
        ret = min(rec(node+1,1), rec(node+1,0));
        break;
    }

    ret= (RGB[node][col] + ret);
    return ret;
}

int main()
{
    ll t, cas=1, r, g, b;
    scanf("%lld", &t);
    while(t--)
    {
        clr(dp, -1);
        scanf("%lld", &n);
        for (ll i = 0; i<n; i++) scanf("%lld %lld %lld", &RGB[i][0], &RGB[i][1], &RGB[i][2]);
        printf("Case %lld: %lld\n",cas++, min(rec(0,0), min(rec(0,1), rec(0,2))));
    }
    return 0;
}
