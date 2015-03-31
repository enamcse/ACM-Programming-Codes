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

#define sz 1000
#define pb(a) push_back(a)
#define pp pop_back()
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

vector<int> adj[sz],cost[sz];

bool bellman_ford(int n, int m, int s)
{
    //initialize
    int dist[n];
    for (int i = 1; i<n; i++)
        dist[i]=inf;
    dist[s]=0;

    //relaxation of paths
    for (int i =0; i<n; i++)
        for (int j = 0; j<adj[i].size(); j++)
            if(dist[i]+cost[i][j]<dist[adj[i][j]])
                dist[adj[i][j]] = dist[i]+cost[i][j];

    //checking negative-cycle
    for (int i =0; i<n; i++)
        for (int j = 0; j<adj[i].size(); j++)
            if(dist[i]+cost[i][j]<dist[adj[i][j]])
                return true;
    return false;
}

int main()
{
    int n, m, x, y, t , z;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i<n; i++)
            adj[i].clear(),cost[i].clear();

        for (int i = 0; i<m; i++)
        {
            scanf("%d %d %d", &x, &y, &z);
            adj[x].pb(y);
            cost[x].pb(z);
        }
        if(bellman_ford(n,m,0)) printf("possible\n");
        else printf("not possible\n");
    }
	return 0;
}
