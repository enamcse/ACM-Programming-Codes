//Verdict: NOT SOLVED
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

#define sz 2005
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

struct edge
{
    int u, v, w;
    edge() {}
    edge(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
};

int grid[sz][sz];
vector<edge>e;
int par[sz];

int find_par(int n)
{
    return par[n] = (par[n]==n?n:find_par(par[n]));
}

void init(int n)
{
    for (int i = 0; i<n; i++)
        par[i] = i;
    return;
}

vector<int>adj[sz], cost[sz];

bool comp(const edge &a,const edge &b)
{
    return a.w<b.w;
}

int mst(int n)
{
    sort(e.begin(), e.end(), comp);
    int len = e.size(), x, y, ret=n-1;

    for (int i = 0; i<len; i++)
    {
        x = find_par(e[i].u);
        y = find_par(e[i].v);
        if(x!=y)
        {
            par[x] = y;
            adj[ e[i].u ].pb(e[i].v);
            adj[ e[i].v ].pb(e[i].u);
            cost[ e[i].u ].pb(e[i].w);
            cost[ e[i].v ].pb(e[i].w);
            ret--;
        }
    }
    return ret;
}


ll node[sz];
struct junc
{
    int u;
    ll w;
    junc() {}
    junc(int a, ll c)
    {
        u = a;
        w = c;
    }
    bool operator < (const junc &p) const
    {
        return w > p.w;
    }
};

priority_queue<junc>data;

void dijkstra(int s, int n)
{
    for (int i = 0; i<n; i++)
        node[i]=inf;

    node[s] = 0;
    data.push(junc(s,0));
    junc p;
    while(!data.empty())
    {
        p = data.top();
        for (int i = 0; i<adj[ p.u ].size(); i++)
        {
            if(node[p.u]+ cost[p.u][i]< node[ adj[p.u][i] ])
            {
                node[ adj[p.u][i] ] = node[p.u] + cost[p.u][i];
                data.push(junc(adj[p.u][i], node[ adj[p.u][i] ]));
            }
        }
        data.pop();
    }
    return;
}


bool flag=true;

int main()
{
    int n;
    scanf("%d", &n);
    init(n);
    for (int i = 0; i<n; i++)
        for (int j =  0; j<n; j++)
            scanf("%d", &grid[i][j]);

    for (int i = 0; i<n; i++)
    {
        if(grid[i][i]!=0)
        {
            flag = false;
            break;
        }
        for (int j = i+1; j<n; j++)
        {
            if(grid[i][j]==grid[j][i])
            {
                if(grid[j][i])e.pb(edge(i, j, grid[i][j]));
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    if(flag) flag = mst(n)==0;
    if(flag)
    {
        for (int i = 0; i<n; i++)
        {
            dijkstra(i,n);
            for (int j = 0; j<n; j++)
                if((ll)grid[i][j]!=node[j])
                {
                    flag = false;
                    break;
                }
            if(!flag) break;
        }
    }

    if(flag) puts("YES");
    else puts("NO");

    return 0;
}
