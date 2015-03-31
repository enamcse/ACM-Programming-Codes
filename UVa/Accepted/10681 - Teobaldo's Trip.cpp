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

#define sz 105
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

int c, l, s, e, d;

vector<int>adj[sz];
int dp[sz][2*sz];

int rec(int node, int rem)
{
    if(rem==0&&node!=e) return -inf;
    else if (rem==0) return 0;
    int &ret = dp[node][rem];
    if(ret!=-1) return ret;
    int len = adj[node].size();
    ret = -inf;
    for (int i = 0; i<len; i++)
    {
        if(adj[node][i]!=node) ret = max(ret,rec(adj[node][i],rem-1));
    }
    return ret;
}

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int a, b, k;
    while(~scanf("%d %d", &c, &l)&&(c||l))
    {
        for (int i = 1; i<=c; i++) adj[i].clear();
        clr(dp,-1);
        for (int i = 0; i<l; i++)
        {
            scanf("%d %d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }

        scanf("%d %d %d", &s, &e, &d);
        k = rec(s,d);
        if(k<0) printf("No, Teobaldo can not travel.\n");
        else printf("Yes, Teobaldo can travel.\n");

    }

    return 0;
}
