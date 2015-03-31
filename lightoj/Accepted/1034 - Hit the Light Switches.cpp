//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define all(a,b,c)      for(int I=0;I<b;I++)    a[I] = c
#define BE(a)           a.begin(),a.end()
#define chng(a,b)       a^=b^=a^=b;
#define clr(y,z)        memset(y,z,sizeof(y))
#define cntbit(mask)     __builtin_popcount(mask)
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define EQ(a,b)         (fabs(a-b)<ERR)
#define ERR             1e-5
#define FORE(i,a)       for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define fr(i,a,b)       for(i=a;i<=b;i++)
#define fread           freopen("input.txt","r",stdin)
#define fri(a,b)        for(int i=a;i<=b;i++)
#define frj(a,b)        for(int j=a;j<=b;j++)
#define frk(a,b)        for(int k=a;k<=b;k++)
#define frl(a,b)        for(int l=a;l<=b;l++)
#define frin(a,b)       for(int i=a;i>=b;i--)
#define frjn(a,b)       for(int j=a;j>=b;j--)
#define frkn(a,b)       for(int k=a;k>=b;k--)
#define frln(a,b)       for(int l=a;l>=b;l--)
#define frn(i,a,b)      for(i=a;i>=b;i--)
#define fwrite          freopen("output.txt","w",stdout)
#define inf             (1e9)
#define inpow(a,x,y)    int i; a=x;fri(2,y)  a*=x
#define makeint(n,s)    istringstream(s)>>n
#define mod             1000000007
#define ISS             istringstream
#define ll              long long
#define oo              (1<<30)
#define OSS             ostringstream
#define pb              push_back
#define PI              3.141592653589793
#define pi              (2*acos(0))
#define pp              pop_back
#define PRE             1e-8
#define print1(a)       cout<<a<<endl
#define print2(a,b)     cout<<a<<" "<<b<<endl
#define print3(a,b,c)   cout<<a<<" "<<b<<" "<<c<<endl
#define rev(a)          reverse(BE(a));
#define round(i,a)      i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define SI              set<int>
#define SII             set<int>::iterator
#define SIZE(s)         ((int)s.size())
#define saja(a)        sort(BE(a))
#define sqr(a)          ((a)*(a))
#define SZ              100005
#define SZ1             55
#define typing(j,b)     typeof((b).begin()) j=(b).begin();
#define VD              vector<double>
#define VI              vector<int>
#define VLL             vector<long long>
#define VS              vector<string>

int col[SZ],low[SZ],tim[SZ],timer, in_deg[SZ];
int group_id[SZ],n,m,components;
stack<int>S;
VI adj[SZ];

void scc(int u)
{
    int i,v,tem;
    col[u]=1;
    low[u]=tim[u]=timer++;
    S.push(u);
    fr(i,0,SIZE(adj[u])-1)
    {
        v=adj[u][i];
        if(col[v]==1)
            low[u]=min(low[u],tim[v]);
        else if(col[v]==0)
        {
            scc(v);
            low[u]=min(low[u],low[v]);
        }
    }

    if(low[u]==tim[u])
    {
        do
        {
            tem=S.top();
            S.pop();
            group_id[tem]=components;
            col[tem]=2;
        }
        while(tem!=u);
        components++;
    }
}

int TarjanSCC()
{
    int i;
    timer=components=0;
    clr(col,0);
    while(!S.empty()) S.pop();
    fr(i,0,n-1) if(col[i]==0) scc(i);
    return components;
}

VI nadj[SZ];
void MakeNewDAG_Graph()
{
    int i,j,u,v;

    fr(i,0,components-1) nadj[i].clear();

    fr(i,0,n-1)
    {
        fr(j,0,SIZE(adj[i])-1)
        {
            u=group_id[i];
            v=group_id[adj[i][j]];
            if(u!=v)
                nadj[u].pb(v);
        }
    }
}


int main()
{
    int i,j,t,cas=0,u,v,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        fr(i,0,n-1) adj[i].clear();
        fr(i,1,m)
        {
            scanf("%d %d",&u,&v);
            adj[u-1].pb(v-1);
        }
        TarjanSCC();
        MakeNewDAG_Graph();

        fr(i,0,components-1)
            in_deg[i]=0;

        fr(i,0,components-1)
        {
            fr(j,0,SIZE(nadj[i])-1)
            {
                in_deg[ nadj[i][j] ]++;
            }
        }

        ans = 0;

        fr(i,0,components-1)
        {
            if(!in_deg[i]) ans++;
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
