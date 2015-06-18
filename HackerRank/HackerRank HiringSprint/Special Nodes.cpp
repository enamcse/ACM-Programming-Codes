/**
* H:\Dropbox\Code\HackerRank\HackerRank HiringSprint\Special Nodes.cpp
* Created on: 2015-06-14-16.42.32, Sunday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 200005
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

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
void dijkstra()
{
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
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,u,v,w;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n>>m;

    for (int i = 0; i<m; i++)
    {
        cin>>u>>v>>w;
        adj[u].pb(v);
        adj[v].pb(u);
        cost[v].pb(w);
        cost[u].pb(w);
    }

    for (int i = 0; i<=n; i++)
        node[i] = (int)INFINITY;

    cin>>t;

    for (int i = 0; i<t; i++)
    {
        cin>>m;
        node[m]=0;
        data.push(junc(m,0));
    }

    dijkstra();

    for (int i = 1; i<=n; i++)
        cout<<node[i]<<"\n";

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
