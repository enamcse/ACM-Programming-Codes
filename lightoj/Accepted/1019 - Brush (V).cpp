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
#include <stack>

#define sz 155
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

vector<int>adj[sz],cost[sz];
int node[sz];

struct junc{
    int u, w;
    junc(){}
    junc(int a,  int c)
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

int dijkstra(int s, int e)
{
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
    return node[e];
}

int main()
{
    int t, n, m, cas=1,x,y,w;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i<n; i++)
            adj[i].clear(), cost[i].clear(), node[i]=inf;

        for (int i = 0; i<m; i++)
        {
            scanf("%d %d %d", &x, &y, &w);
            adj[y-1].pb(x-1);
            adj[x-1].pb(y-1);
            cost[y-1].pb(w);
            cost[x-1].pb(w);
        }

        w=dijkstra(0,n-1);
        if(w<inf) printf("Case %d: %d\n",cas++,w);
        else printf("Case %d: Impossible\n",cas++);
    }


    return 0;
}
