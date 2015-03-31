#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define sz 55
#define pb(a) push_back(a)
#define inf (1e9)

using namespace std;

struct edge
{
    int u, v, w;
    edge() {}
    edge(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
};
vector<edge>e;

int par[sz];

int find_par(int n)
{
    return par[n] = (par[n]==n?n:find_par(par[n]));
}

void init(int n)
{

    for (int i = 0; i<n; i++)
        par[i] = i;
    return;
}
bool comp(edge a, edge b)
{
    return a.w<b.w;
}
int mst(int n)
{
    sort(e.begin(), e.end(), comp);
    int len = e.size(), x, y, ret=0;
    vector<int>k;
    for (int i = 0; i<len; i++)
    {
        x = find_par(e[i].u);
        y = find_par(e[i].v);
        if(x!=y)
        {
            par[x] = y;
            k.pb(i);
            ret+=e[i].w;
        }
    }

    if(k.size()<n-1) return -1;
    else return ret;
}

map<string, int>mp;

int main()
{
    int t, n,m, cas=1, c;
    char line[51], line1[51];
    scanf("%d", &t);

    while(t--)
    {
        e.clear();
        n =0;
        mp.clear();
        scanf("%d", &m);

        for (int i = 0; i<m; i++)
        {
            scanf("%s %s %d", line, line1, &c);
            if(mp.find(line)==mp.end()) mp[line]=n++;
            if(mp.find(line1)==mp.end())mp[line1]=n++;
            e.pb(edge(mp[line],mp[line1],c));
        }

        init(n);
        c = mst(n);
        if(c!=-1)printf("Case %d: %d\n", cas++, c);
        else printf("Case %d: Impossible\n", cas++);
    }

    return 0;
}
