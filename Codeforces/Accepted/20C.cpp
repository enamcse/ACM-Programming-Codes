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

#define sz 100055
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e17)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

ll node[sz], par[sz];

vector<ll>adj[sz],cost[sz];

struct data{
    ll nong, w;
    data(){}
    data(ll a, ll b)
    {
        nong = a;
        w = b;
    }

    bool operator < (const data &k) const
    {
        return k.w<w;
    }
};

priority_queue<data>p;
void init(ll n)
{
    for (ll i = 0; i<n; i++)
        node[i]=inf, par[i]=-1;
    return;
}

ll dijkstra(ll source, ll dest)
{
    node[source] = 0;
    p.push(data(0,0));

    while(!p.empty())
    {
        for (ll i = 0; i<adj[p.top().nong].size(); i++)
        {
            if(node[ p.top().nong ]+ cost[p.top().nong][i] < node[ adj[p.top().nong][i] ])
            {
                par[ adj[p.top().nong][i] ] = p.top().nong;
                node[ adj[p.top().nong][i] ] = node[ p.top().nong ]+ cost[p.top().nong][i];
                p.push(data(adj[p.top().nong][i], node[ adj[p.top().nong][i] ]));
            }
        }
        p.pop();
    }
    return (node[dest]>=inf?-1:node[dest]);
}



int main()
{
    ll t, n, m, cas=1,x,y,z;


    scanf("%lld %lld", &n, &m);
    init(n);
    for (ll i = 0; i<m; i++)
    {
        scanf("%lld %lld %lld", &x, &y, &z);
        adj[x-1].pb(y-1);
        adj[y-1].pb(x-1);
        cost[x-1].pb(z);
        cost[y-1].pb(z);
    }
    z = dijkstra(0, n-1);
    if(z==-1) printf("-1");
    else
    {
        stack<ll>q;
        z = n - 1;
        q.push(z);
        while(par[z]!=-1)
        {
            q.push(par[z]);
            z = par[z];
        }

        while(!q.empty())
        {
            if(q.size()!=1) printf("%lld ", q.top()+1);
            else printf("%lld", q.top()+1);
            q.pop();
        }
    }
    return 0;
}
