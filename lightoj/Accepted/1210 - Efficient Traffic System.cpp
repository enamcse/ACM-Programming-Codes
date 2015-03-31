/*
 * 1210 - Efficient Traffic System.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: Enamul
 */

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

#define sz 20005
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

vector<int> adj[50005];

int comp, col[sz], dis[sz], height[sz], tim, component[sz];
stack<int> s;

void scc(int u)
{
    s.push(u);
    int v, len = adj[u].size();
    dis[u] = height[u] = tim++;
    for (int i = 0; i < len; ++i)
    {
        v = adj[u][i];
        if (col[v] == 0)
        {
            col[v] = 1;
            scc(v);
            height[u] = min(height[u], height[v]);
        }
        else if (col[v] == 1)
        {
            height[u] = min(height[u], height[v]);
        }
    }
    if (height[u] == dis[u])
    {
        col[u] = 2;
        component[u]=comp;
        while (s.top() != u)
        {
            v = s.top();
            s.pop();
            col[v] = 2;
            component[v]=comp;
        }
        s.pop();
        comp++;
    }
}

int dag(int n)
{
    vector<int>comp_adj[comp];
    int len,v, root,leaf;
    bool in_deg[comp],out_deg[comp];

    for (int i = 0; i<comp; i++)
        in_deg[i]=out_deg[i]=false;

    for (int i = 0; i<n; i++)
    {
        len = adj[i].size();

        for (int j = 0; j<len; j++)
        {
            v = adj[i][j];
            if(component[i]!=component[v])
            {
                comp_adj[ component[i] ].pb(component[v]);
                out_deg[ component[i] ] = true;
                in_deg[ component[v] ] = true;
            }
        }
    }
    root=leaf=0;

    for (int i = 0; i<comp; i++)
    {
        if(!in_deg[i]) root++;
        if(!out_deg[i]) leaf++;
    }
    return (comp==1?0:max(root, leaf));
}

int main(int argc, char **argv)
{
    int t, n, m, cas = 1, x, y, graph;
    scanf("%d", &t);
    while (t--)
    {
        graph = tim = comp = 0;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i)
        {
            adj[i].clear();
            col[i] = 0;
        }
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d", &x, &y);
            adj[x - 1].pb(y-1);
        }


        for (int j = 0; j < n; ++j)
        {
            if (!col[j])
            {
                col[j] = 1;
                scc(j);
            }
        }
        printf("Case %d: %d\n", cas++, dag(n));


    }
    return 0;
}

