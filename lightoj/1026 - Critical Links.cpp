/**
* H:\Dropbox\Code\lightoj\1026 - Critical Links.cpp
* Created on: 2015-03-22-20.14.51, Sunday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define SZ(a) ((int)a.size())
#define sz 10005
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

int tim[sz],low[sz];
int timer;
vector<int> adj[sz]; //only adj should be cleared

vector<pair<int,int> > bridge;//the ans(should be cleared)

void dfs(int u,int par) //par=-1 dhore call dite hobe(root ar parent nai)
{
    tim[u] = low[u] = ++timer;

    for(int i = 0 ; i<SZ(adj[u]) ; i++)
    {
        int v = adj[u][i];
        if(v==par) continue;
        if(!tim[v])
        {
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v]>tim[u]) //attention greater equals for bridge and articulation point
            {
               bridge.pb(make_pair(min(u,v), max(u,v)));
            }
        }
        else  //determining back edge
        {
            low[u] = min(low[u],tim[v]);
        }
    }
    return;
}

//sometimes change needed here
void bridges(int n)
{
    clr(tim,0);
    timer=0;
    for(int i=0;i<n;i++)
    if(!tim[i])
        dfs(i,-1);
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,u,v;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    vector< pair<int,int> >edges;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);

        edges.clear();
        for (int i = 0; i<n; i++)
        {
            scanf("%d", &u);
            scanf(" (%d) ", &m);
            for (int i = 0; i<m; i++)
            {
                scanf("%d", &v);
                edges.pb(make_pair(min(u,v),max(u,v)));
            }
        }

        unify(edges);

        for (int i = 0; i<SZ(edges); i++)
        {
            u = edges[i].first;
            v = edges[i].second;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        bridges(n);
        sort(all(bridge));
        m = SZ(bridge);
        printf("Case %d:\n%d critical links\n", cas++, m);
        for (int i = 0; i<m; i++)
            printf("%d - %d\n", bridge[i].first,bridge[i].second );
        for (int i = 0; i<n; i++)
            adj[i].clear();
        bridge.clear();
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
