#include <stdio.h>
#include <vector>
#include <algorithm>


#define sz 105
#define pb(a) push_back(a)
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
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

    for (int i = 0; i<=n; i++)
        par[i] = i;

    return;
}

bool comp(edge a, edge b)
{
    return a.w<b.w;
}

void mst(int n)
{
    sort(e.begin(), e.end(), comp);
    pair<int, int>p(0,0);
    int len = e.size(), x, y;

    for (int i = 0; i<len; i++)
    {
        x = find_par(e[i].u);
        y = find_par(e[i].v);
        if(x!=y)
        {
            p.first += e[i].w;
            par[x] = y;
        }
    }
    init(n);
    reverse(e.begin(), e.end());
    for (int i = 0; i<len; i++)
    {
        x = find_par(e[i].u);
        y = find_par(e[i].v);
        if(x!=y)
        {
            p.second += e[i].w;
            par[x] = y;
        }
    }
    if((p.first+p.second)%2) printf("%d/2\n", p.first+p.second);
    else printf("%d\n", ((p.first+p.second)>>1));
    return;
}



int main()
{
    #ifdef ENAM
    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1, v,u,w;

    scanf("%d", &t);

    while(t--)
    {
        e.clear();
        scanf("%d", &n);
        init(n);
        while(~scanf("%d %d %d", &u, &v,&w)&&(u||v||w)) e.pb(edge(u,v,w));
        printf("Case %d: ", cas++);
        mst(n);
    }

    return 0;
}
