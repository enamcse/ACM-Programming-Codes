#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <bitset>

using namespace std;

#define inf 1e9
#define pb push_back
#define pp pop_back
#define clr(y,z) memset(y, z, sizeof(y))
#define mp make_pair
#define BE(a) a.begin(),a.end()
#define ll long long
#define sz 10005

vector<int>adj[sz];

int n,mx,mx2;
bool col[sz];


void dfs(int node, int cost, int par)
{
//    cout<<node<<" "<<cost<<" "<<par<<endl;
    col[node] = true;
    if(cost>mx) mx = cost, mx2 = node;
    if(adj[node].size()==1&&par!=-1) return;
    int len = adj[node].size();
    for (int i = 0; i<len; i++)
    {
        if(col [ adj[node][i] ] == true ||adj[node][i] == par) continue;
        dfs(adj[node][i], cost+1, node);
    }
    return;
}

int bfs(int p)
{
    clr(col,false);
    queue< pair<int,int> >q;
    q.push(mp(p,0));
    col[p] = true;
    mx =0;
    while(!q.empty())
    {
        mx = max(mx,q.front().second );
        int now = q.front().first, u;
        int len = adj[now].size();
        for (int i = 0; i<len; i++)
        {
            u = adj[now][i];
            if(col[u]) continue;
            col[u] = true;
            q.push(mp(u,1+q.front().second));
        }
        q.pop();
    }

    return mx;
}


int main()
{
    int u, v, m;
    scanf("%d", &n);
    m = n-1;
    for (int i = 0; i<m; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u-1].pb(v-1);
        adj[v-1].pb(u-1);
    }

    for (int i = 0; i<n; i++)
    {
        if(adj[i].size()>0) {dfs(i,0,-1);break;}
    }

    bfs(mx2);

    printf("%d", mx);

    return 0;
}
