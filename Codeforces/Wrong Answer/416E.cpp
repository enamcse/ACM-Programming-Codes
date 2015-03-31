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

#define sz 505
#define pb(a) push_back(a)

#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

vector<int>adj[sz], co[sz];
int col[sz];

struct datas
{
    int u,cost;
    bool operator < ( const datas& p ) const
    {
        return cost > p.cost;
    }
    datas(int a, int c)
    {
        u = a;
        cost = c;
    }
};

priority_queue<datas>pq;
set< pair<int,int> >sss[sz];

int dijkstra(int source, int dest, int n)
{
    int xx,xxx,pp, puru;
    for (int i = 0; i<n; i++)
        col[i] = inf, sss[i].clear();
    col[source] = 0;
    pq.push(datas(source,col[source]));
//cout<<"hre";
    while(!pq.empty())
    {
        source = pq.top().u;
        pq.pop();
        puru = adj[source].size();
        for (int i =0; i<puru; i++)
        {
            pp=adj[source][i];
            if(col[source]+co[source][i]==col[pp])
            {
                int len = sss[source].size();
                for (set< pair<int,int>  >:: iterator it =  sss[source].begin(); it!=sss[source].end(); it++)
                {
                    sss[ pp ].insert(*it);
                }
                xx = min(pp, source);
                xxx = max(pp, source);
                sss[ pp ].insert(make_pair(xx,xxx));
            }
            else if(col[source]+co[source][i]<col[pp])
            {
                xx = min(pp, source);
                xxx = max(pp, source);
                sss[ pp ] = sss[ source ];
                sss[ pp ].insert(make_pair(xx,xxx));
                col[pp] = col[source]+co[source][i];
                pq.push(datas(pp,col[pp]));
            }
        }
    }
    return sss[dest].size();
}

int main()
{
    int v,s,d,e,cost;
    vector<int>ans;
    scanf("%d %d", &v, &e);
    {
        ans.clear();
        for (int i =0; i<e; i++)
        {
            scanf("%d %d %d", &s, &d, &cost);

            adj[s-1].pb(d-1);
            adj[d-1].pb(s-1);
            co[s-1].pb(cost);
            co[d-1].pb(cost);
        }
        for (int i = 0; i<v; i++)
            for (int j = i+1; j<v; j++)
                ans.pb(dijkstra(i,j,v));

        d = ans.size();
        d--;
        for (int i = 0; i<d; i++)
            printf("%d ", ans[i]);
        printf("%d\n", ans[d]);

    }
    return 0;
}
