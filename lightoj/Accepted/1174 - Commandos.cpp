#include <stdio.h>
#include <algorithm>


#define sz 105
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e8)

int adj[sz][sz];

void floyed_warshall(int n)
{
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
        {
            if(i==j) continue;
            for (int k = 0; k<n; k++)
            {
                if(i==k || j==k) continue;
                adj[j][k] = std::min(adj[j][k], adj[j][i]+adj[i][k]);
            }
        }
    return;
}

void init(int n)
{
    for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
                adj[i][j] = inf;
            adj[i][i] = 0;
        }
    return;
}

int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM
    int t, n, m, cas=1, u, v;

    scanf("%d", &t);

    while(t--)
    {

        scanf("%d %d", &n, &m);

        init(n);

        for (int i = 0; i<m; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        floyed_warshall(n);

        scanf("%d %d", &u, &v);
        m = (n==1?0:1);
        for (int i = 0; i<n; i++)
            if(i!=u&&i!=v) m = std::max(m, adj[u][i]+adj[i][v]);

        printf("Case %d: %d\n", cas++, m);
    }

    return 0;
}
