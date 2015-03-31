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

#define sz 10
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

vector<int>adj[sz],cost[sz];
int intersect[sz], direction[sz];
int n;

struct node{
    int name,delay;
    bool operator <(const node &p)const
    {
        return delay>p.delay;
    }
};

void init()
{
    for (int i = 0; i<n; i++)
    {
        intersect[i]=inf;
        adj[i].clear();
        cost[i].clear();
    }
    return;
}

void dijkstra(int x)
{
    priority_queue<node>pq;
    node u,v;
    u.name=x;
    u.delay=0;
    intersect[x]=0;
    direction[x]=-1;
    pq.push(u);
    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();

        int s = adj[u.name].size();
        for (int i = 0; i<s; i++)
        {
            if(intersect[adj[u.name][i]]>intersect[u.name]+cost[u.name][i])
            {
                v.name = adj[u.name][i];
                v.delay = intersect[u.name]+cost[u.name][i];
                intersect[v.name] = v.delay;
                direction[v.name]=u.name;
                pq.push(v);
            }
        }
    }
    return;
}

void path_print(int x)
{
    stack<int>path;
    path.push(x);
    int k = direction[x];
    while(k!=-1)
    {
        path.push(k);
        k = direction[k];
    }
    while(!path.empty())
    {
        printf(" %d", path.top()+1);
        path.pop();
    }
    return;
}

int main()
{
    int x,y,c,cas=1;
    while(~scanf("%d", &n)&&n)
    {
        init();
        for (int i = 0; i<n; i++)
        {
            scanf("%d", &x);
            for (int j = 0; j<x; j++)
            {
                scanf("%d %d", &y, &c);
                adj[i].pb(y-1);
                cost[i].pb(c);
            }
        }
        scanf("%d %d", &y, &c);//cout<<"hree!!"<<endl;
        dijkstra(y-1);
        printf("Case %d: Path =",cas++);
        path_print(c-1);
        printf("; %d second delay\n",intersect[c-1]);

    }
	return 0;
}
