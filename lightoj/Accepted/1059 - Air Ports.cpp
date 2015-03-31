#include <stdio.h>
#include <vector>
#include <algorithm>

#define sz 10005
#define pb(a) push_back(a)
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;

int a;

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

inline int find_par(int n)
{
    return par[n] = (par[n]==n?n:find_par(par[n]));
}

inline void init(int n)
{
    for (int i = 0; i<n; i++)
        par[i] = i;
    return;
}

inline bool comp(edge a, edge b)
{
    return a.w<b.w;
}

void mst(int n)
{
    sort(e.begin(), e.end(), comp);
    init(n);
    int len = e.size(), x, y, ret=0;
    for (int i = 0; i<len; i++)
    {
        if(e[i].w>=a) break;
        x = find_par(e[i].u);
        y = find_par(e[i].v);
        if(x!=y)
        {
            par[x] = y;
            ret+=e[i].w;
            n--;
        }
    }
    ret+=n*a;

    printf("%d %d\n", ret, n);
    return;
}

int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    int t, n,m, cas=1, u, v, c;

    scanf("%d", &t);

    while(t--)
    {
        e.clear();
        scanf("%d %d %d", &n, &m, &a);
        for (int i = 0; i<m; i++)
        {
            scanf("%d %d %d", &u, &v, &c);
            e.pb(edge(u-1,v-1,c));
        }
        printf("Case %d: ", cas++ );
        mst(n);
    }
    return 0;
}
