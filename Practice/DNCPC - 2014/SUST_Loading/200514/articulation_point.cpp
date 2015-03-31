#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<sstream>

#define mp          make_pair
#define pb          push_back
#define FOR(i,a,b)  for(__typeof(a) i=(a);i<b;i++)
#define SZ(a)       (int)a.size()
#define all(a)      (a).begin(),(a).end()
#define clr(a)       a.clear()
#define mem(a,b)    memset(a,b,sizeof(a))

using namespace std;

#define MAX  10005

int N,M,low[MAX],idx[MAX],col[MAX],numofArt,artpoint[MAX],ti;
vector<int> adj[MAX];

void dfs(int u,int p=-1)
{
    col[u]=1;low[u]=idx[u]=++ti; int subtree=0;
    FOR(i,0,SZ(adj[u]))
    {
        int v=adj[u][i];
        if(v==p)continue;
        if(col[v]) low[u]=min(low[u],idx[v]);
        else
        {
            subtree++;
            dfs(v,u);
            low[u]=min(low[v],low[u]);
            if(low[v]>=idx[u] and p!=-1)artpoint[u]=1;
        }
    }
    if(p==-1 and subtree>1) artpoint[u]=1;
    return;
}

void Articulationpoint()
{
    FOR(i,0,N+1)
    {
        low[i]=idx[i]=col[i]=artpoint[i]=0;
    }

    numofArt=ti=0;
    FOR(i,1,N+1)
    {
        if(col[i]==0)dfs(i);
    }
    FOR(i,1,N+1) if(artpoint[i]) numofArt++;
    return;
}


int main()
{
    int cas=0;int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&N,&M);
        FOR(i,0,N+1) (adj[i].clear());
        int x,y;
        FOR(i,0,M)
        {
            scanf("%d %d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        Articulationpoint();
        printf("Case %d: %d\n",++cas,numofArt);
    }
    return 0;
}

