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

