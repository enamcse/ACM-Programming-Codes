#include <stdio.h>
#include <vector>
#include <algorithm>

#define sz 55
#define pb(a) push_back(a)
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)

using namespace std;

struct edge{
    int u, v, w;
    edge(){}
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
        }
        else ret+=e[i].w;
    }

    if(k.size()<n-1) return -1;
    else return ret;
}

int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM
    int t, n,m, cas=1;

    scanf("%d", &t);

    while(t--)
    {
        e.clear();
        scanf("%d", &n);
        init(n);

        for (int i = 0; i<n; i++)
            for (int j = 0; j<n; j++)
            {
                scanf("%d", &m);
                if(m) e.pb(edge(i,j,m));
            }

            printf("Case %d: %d\n", cas++, mst(n));
    }

    return 0;
}
