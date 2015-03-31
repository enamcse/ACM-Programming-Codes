#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cctype>
#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))

using namespace std;

int dfs(int cur, bool flag);
vector<int>adj[sz];
int cost[sz][sz],n;
bool dir[sz][sz];
bool color[sz];

int main()
{
    int n, a, b, c, T, caseno=1, mins;
    scanf("%d", &T);

    while(T--)
    {
        clr(cost,0);
        clr(dir,true);
        scanf("%d", &n);

        for (int i = 0; i<n; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            adj[a-1].pb(b-1);
            adj[b-1].pb(a-1);
            cost[b-1][a-1]=cost[a-1][b-1]=c;
            dir[b-1][a-1] = false;
        }
        clr(color,false);
        mins = min(dfs(0,true),dfs(0,false));
        printf("Case %d: %d\n",caseno++,mins);
    }
    return 0;
}

int dfs(int cur, bool flag)
{
    color[cur] = true;
    int u = adj[cur][0], a, b;
    int v = adj[cur][0];
    if(!color[u])
    {
        a=dfs(u, flag);
    }
    else
    {
        if(dir[cur][u]==flag) return cost[cur][u];
        else return 0;
    }
    if(!color[v])
    {
        b=dfs(v, flag);
    }
    else
    {
        if(dir[cur][v]==flag) return cost[cur][v];
        else return 0;
    }
    if(dir[cur][u]==flag) a+=cost[cur][u];
    if(dir[cur][v]==flag) b+=cost[cur][v];
    return min(a,b);
}

