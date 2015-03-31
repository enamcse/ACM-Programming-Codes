#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <string.h>

using namespace std;

#define clr(y,z) memset(y,z, sizeof(y))
#define cntbit(mask) _builtin_popcount(mask)
#define fs first
#define sc second
#define pb push_back
#define pp pop_back
#define chg(a, b) a^=b^=a^=b
#define sz 2005
#define inf (1e9)
#define ll long long

ll arr[sz];
ll dp[sz][sz];


ll rec(int s, int e, int cnt, int tot)
{
    if(s>e) return 0;
    ll &ret = dp[s][e];
    if(ret!=-1) return ret;
    ret =  max(rec(s+1,e, cnt+1, tot)+arr[s]*(cnt+1), rec(s,e-1, cnt+1, tot)+arr[e]*(cnt+1));
    return ret;
}

int main()
{
    #ifdef ENAM
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif
    int n;
    clr(dp,-1);
    scanf("%d", &n);

    for (int i = 0; i<n; i++)
    	scanf("%lld", &arr[i]);

    printf("%lld", rec(0,n-1LL, 0,0));

    return 0;
}
