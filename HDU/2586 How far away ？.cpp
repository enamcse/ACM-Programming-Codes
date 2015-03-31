#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <string.h>

using namespace std;

#define clr(y,z) memset(y,z, sizeof(y))
#define cntbit(mask) _builtin_popcount(mask)
#define fs first
#define mp make_pair
#define sc second
#define pb push_back
#define pp pop_back
#define chg(a, b) a^=b^=a^=b
#define sz 40005
#define inf (1e9)

vector<int>adj[sz], cost[sz];
int node[sz];

struct point{
    int nn, w;

    point(int a, int b)
    {
        nn = a;
        w = b;
    }
    point(){}

    bool operator <  (point const &r) const
    {
        return r.w < w;
    }
};

priority_queue<point>p;


int dijkstra(int s, int e)
{
    node[s] = 0;
    p.push(point(s,0));
    int w,now, len, hand;


    while(!p.empty())
    {
        now=p.top().nn;
        len = adj[now].size();

        for (int i = 0; i<len; i++)
        {
            hand = adj[now][i];
            if(node[hand] > node[now] + cost[now][i])
            {
                node[hand]=node[now] + cost[now][i];
                p.push( point(hand, node[hand]) );
            }
        }
        p.pop();
    }
    return node[e];
}

void init(int n)
{
    for (int i = 0; i<n; i++)
    	node[i]=inf;
    return;
}

int main()
{
    #ifdef ENAM
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif

    int t, n, m, k,x ,y ,z;
    scanf("%d", &t);

    while(t--)
    {

        scanf("%d %d", &n , &m);

        for (int i = 0; i<n; i++)
        {
            adj[i].clear();
            cost[i].clear();
        }

        for (int i = 0; i<n-1; i++)
        {
            scanf("%d %d %d", &x, &y, &z);
            adj[x-1].pb(y-1);
            cost[x-1].pb(z);
            adj[y-1].pb(x-1);
            cost[y-1].pb(z);
        }


        for (int i = 0; i<m; i++)
        {
            while(!p.empty()) p.pop();
            init(n);
            scanf("%d %d", &x, &y);
            printf("%d\n",dijkstra(x-1,y-1));
        }


    }



    return 0;
}
