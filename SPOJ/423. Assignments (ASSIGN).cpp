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

#define sz 20
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;
char graph[sz][sz];
ll dp[(1<<sz)];
int n , last;

ll rec(int mask)
{
    if(mask==last) return 1;
    ll &ret = dp[mask];
    if(ret!=-1) return ret;
    ret = 0;
    int stdnt= (int)__builtin_popcount((int)mask);
    for (int i  = 0; i<n; i++)
    {
        if((mask&(1<<i))==0&&graph[stdnt][i]=='1') ret+=(rec((mask|(1<<i))));
    }
    return ret;
}

int main()
{
    int t;
    ll ans;
    scanf("%d", &t);
    while(t--)
    {
        ans =0;
        scanf("%d", &n);
        for (int i =0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
                scanf(" %c", &graph[i][j]);
        }
        clr(dp,-1);
        last = (1<<n)-1;
        for (int i = 0; i<n; i++)
        {
                if(graph[0][i]=='1')
                    ans+=(rec((1<<i)));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
