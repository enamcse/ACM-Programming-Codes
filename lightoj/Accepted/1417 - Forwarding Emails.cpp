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
#define fri(a,b)        for(int ak=a;ak<=b;ak++)
#define frj(a,b)        for(int dui=a;dui<=b;dui++)
#define frk(a,b)        for(int tin=a;tin<=b;tin++)
#define frl(a,b)        for(int chair=a;chair<=b;chair++)
#define frin(a,b)       for(int panch=a;panch>=b;panch--)
#define frjn(a,b)       for(int soy=a;soy>=b;soy--)
#define frkn(a,b)       for(int shaat=a;shaat>=b;shaat--)
#define frln(a,b)       for(int aat=a;aat>=b;aat--)
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
#define SZ              50005
#define SZ1             55
#define typing(j,b)     typeof((b).begin()) j=(b).begin();
#define VD              vector<double>
#define VI              vector<int>
#define VLL             vector<long long>
#define VS              vector<string>

VI adj[SZ];
int col[SZ],low[SZ],tim[SZ],timer, lowest_node[SZ], node_item[SZ];
int group_id[SZ],n,m,components;
stack<int>S;

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
            tem=S.top();S.pop();
            group_id[tem]=components;
            col[tem]=2;
        }while(tem!=u);
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

void add(int ina,int inb)
{
    adj[ina].pb(inb);
}

int dp[SZ];

int dfs(int node, int cnt)
{
    if(dp[node]!=-1) return dp[node];
    int &mn = dp[node];
    mn = cnt;
    int i;
    fr(i,0,SIZE(nadj[node])-1)
        mn += dfs(nadj[node][i],node_item[ nadj[node][i] ]);
    return mn;
}


int main()
{
    int i,j,t,cas=0,u,v,ans,mn;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d",&n);
        fr(i,0,n-1) adj[i].clear();
        fr(i,1,n)
        {
            scanf("%d %d",&u,&v);
            add(u-1,v-1);
        }
        TarjanSCC();
        MakeNewDAG_Graph();

        fr(i,0,components-1)
        {
            lowest_node[i]= oo;
            node_item[i]=0;
        }
        clr(dp,-1);
        fr(i,0,n-1)
        {
            if(!node_item[ group_id[i] ])lowest_node[ group_id[i] ] = i;
            node_item[ group_id[i] ]++;
        }
        mn=0;ans=0;
        fr(i,0,components-1)
        {
            ans = dfs(i,node_item[i]);
            if(ans>mn)
            {
                mn = ans;
                j = lowest_node[i];
            }
        }
        printf("Case %d: %d\n", ++cas,j+1);
    }
    return 0;
}
