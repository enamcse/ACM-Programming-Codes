#include <cstdio>
#include <queue>
#include <vector>
#define sz 1005
#define pb(a) push_back(a)
#define pp pop_back()
#define inf 1e9
using namespace std;

int col[sz], cas=1;
int dist[sz], val[sz];
vector<int> adj[sz],cost[sz];

bool bellman_ford(int n)
{
    //initialize
    for (int i = 1; i<n; i++)
        dist[i]=inf;

    //relaxation of paths
    for(int k=0; k<n-1; k++)
        for (int i =0; i<n; i++)
            for (int j = 0; j<adj[i].size(); j++)
                if(dist[i]+cost[i][j]<dist[adj[i][j]])
                    dist[adj[i][j]] = dist[i]+cost[i][j];

    for (int i = 0; i<n; i++)
        val[i]=dist[i];
    bool flag=false;
    queue<int>q;

    //checking negative-cycle
    for(int k=0; k<n-1; k++)
        for (int i =0; i<n; i++)
            for (int j = 0; j<adj[i].size(); j++)
                if(val[i]+cost[i][j]<val[adj[i][j]]) q.push(i),flag=true;

    int x,len;
    while(!q.empty())
    {
        x = q.front();
        col[ x ]=cas;
        q.pop();
        len = adj[x].size();
        for (int i = 0; i<len; i++)
            if(col[ adj[x][i] ]!=cas) col[ adj[x][i] ]=cas,q.push(adj[x][i]);
    }
    return flag;
}
void init(int n)
{
    for (int i = 0; i<n; i++)
        adj[i].clear(),cost[i].clear();
}
int main()
{
    int t, n, m, x, y, z;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        init(n);
        for (int i = 0; i<m; i++)
        {
            scanf("%d %d %d", &x, &y, &z);
            adj[y].pb(x);
            cost[y].pb(z);
        }
        printf("Case %d:",cas);
        bool flag = false;

        if(bellman_ford(n))
        {
            for (int i = 0; i<n; i++)
                if(col[i]==cas) printf(" %d", i);
            puts("");
        }
        else printf(" impossible\n");
        cas++;
    }
	return 0;
}
