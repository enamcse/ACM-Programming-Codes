#include <stdio.h>
#include <vector>
#include <algorithm>

#define sz 200
#define pb(a) push_back(a)
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

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
vector<edge>e,pick;

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
    pick.clear();
    int len = e.size(), x, y, ret=0;
    init(n);
    for (int i = 0; i<len; i++)
    {
        x = find_par(e[i].u);
        y = find_par(e[i].v);
        if(x!=y)
        {
            par[x] = y;
            ret+=e[i].w;
            pick.pb(e[i]);
        }
    }
    e = pick;
    if(e.size()<n-1) return -1;
    else return ret;
}

int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    int t, n,m, cas=1, w, u, v;
    scanf("%d", &t);

    while(t--)
    {
        e.clear();
        scanf("%d %d", &n, &w);

        printf("Case %d:\n", cas++);

        for (int i = 0; i<w; i++)
        {
            scanf("%d %d %d", &u, &v, &m);
            e.insert( lower_bound(e.begin(), e.end(), edge(u-1,v-1,m)  ,comp) , edge(u-1,v-1,m));
            printf("%d\n", mst(n));
        }
    }

    return 0;
}
