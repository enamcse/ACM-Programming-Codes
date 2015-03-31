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

#define sz 5005
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

vector<int>adj[sz], cost[sz];
int nodecost[2][sz];

struct node{
    int n, w;
    node(){}
    node(int x, int y)
    {
        n = x;
        w = y;
    }
    bool operator < (const node &p) const
    {
        return w > p.w;
    }
};

priority_queue<node>q;

void dijkstra()
{
    nodecost[0][0] = 0;
    q.push(node(0,0));
    node now;
    int then, c;
    int len;
    while(!q.empty())
    {
        now = q.top();
        q.pop();
        len = adj[now.n].size();
        for (int i = 0; i<len; i++)
        {
            then = adj[now.n][i];
            c = cost[now.n][i];
            if(now.w+c<nodecost[0][then])
            {
                nodecost[1][then]=nodecost[0][then];
                nodecost[0][then]= now.w+c;
                q.push(node(then,nodecost[0][then]));
            }
            else if(now.w+c<nodecost[1][then] && now.w+c!= nodecost[0][then])
            {
                nodecost[1][then]= now.w+c;
                q.push(node(then,nodecost[1][then]));
            }
        }
    }
    return ;
}

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1, u, v, w;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &n, &m);

        for (int i = 0; i<n; i++)
        {
            adj[i].clear();
            cost[i].clear();
            nodecost[0][i] = inf;
            nodecost[1][i] = inf;
        }

        for (int i = 0; i<m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            adj[u-1].pb(v-1);
            adj[v-1].pb(u-1);
            cost[u-1].pb(w);
            cost[v-1].pb(w);
        }

        dijkstra();

        printf("Case %d: %d\n", cas++, nodecost[1][n-1]);
    }
    return 0;
}
/*
2
3 3
1 2 100
2 3 200
1 3 50
4 4
1 2 100
2 4 200
2 3 250
3 4 100
*/
