//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include <set>
#include <string>
#include <stack>
#include <bitset>

#define sz 1005
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

int w[sz], p[sz],n, m;
int total;
int dp[sz][100];
int rec(int pos, int wt)
{
    if(pos==n) return 0;
    int &ret = dp[pos][wt];
    if(ret!=-1) return ret;
    int p1=0, p2=0;
    if(wt+w[pos]<=m) p1 = p[pos]+rec(pos+1, wt+w[pos]);
    p2 = rec(pos+1, wt);
    return ret=max(p1,p2);
}

int main()
{
    #ifdef ENAM
    	fread;
//	fwrite;
    #endif // ENAM
    int t, cas=1, g;

    scanf("%d",&t);

    while(t--)
    {
        total = 0;
        scanf("%d",&n);
        for (int i = 0; i<n; i++)
            scanf("%d %d", &p[i], &w[i]);
        scanf("%d",&g);
        for (int i = 0; i<g; i++)
        {
            scanf("%d", &m);
            clr(dp,-1);
            total+=rec(0,0);
        }
        printf("%d\n", total);

    }

    return 0;
}
