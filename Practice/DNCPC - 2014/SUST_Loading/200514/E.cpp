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

#define sz 500
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

int n, m, low[sz], idx[sz], col[sz], numofArt, artpoint[sz], ti;
vector <int> adj[sz];
ll total;
void dfs(int u, int p =-1)
{
    col[u]=1;
    low[u]= idx[u]=++ti;
    int subtree=0;

    for (int i = 0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(v==p) continue;
        if(col[v]) low[u]=min(low[u],idx[v]);
        else
        {
            subtree++;
            dfs(v,u);
            low[u] = min(low[v], low[u]);
            if(low[v]>=idx[u] and p!=-1) artpoint[u]=1;
        }
    }
    if(p==-1 and subtree>1) artpoint[u]=1;
    return;
}

void Articulationpoint()
{
    for (int i = 0; i<n+1; i++)
        low[i]=idx[i]=col[i]=artpoint[i]=0;

    numofArt = ti = 0;

    for (int i = 1; i<n+1; i++)
        if(col[i]==0) dfs(i);

    for (int i = 1; i<n+1; i++)
        if(artpoint[i]) numofArt++;
    return;
}


int DFS(int w, int cnt)
{
    if(col[w]==1) return 0;
    col[w]=1;
    int nn = 0, now = 0;
    if(artpoint[w]==1)
    {
        cout<<"w = "<<w<<endl;
        for (int i = 0; i<adj[w].size(); i++)
        {
            col[ adj[w][i] ]=1;
            now = DFS(adj[w][i],0);
            cout<<"now = "<<now<<endl;
            total+= (2*now*(n-now-1));
            nn+=now;
        }
    }
    else
    {
        for (int i = 0; i<adj[w].size(); i++)
        {
            now = DFS(adj[w][i],cnt);
            nn+=now;
        }
    }
    return nn+1;
}

int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    int t,  cas=1,mx, u, v;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &n, &m);
        total=0;
        for (int i = 0; i<m; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u-1].pb(v-1);
            adj[v-1].pb(u-1);
        }
        Articulationpoint();
        clr(col,0);
        DFS(0,0);
        cout<<"here"<<endl;
        printf("Case %d: %d\n",cas++,total);
    }

    return 0;
}
