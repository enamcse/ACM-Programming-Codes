#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 600
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<29-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

void dijkstra(int n, int t);

int graph[sz][sz], node[sz];

int main()
{
    _
    int T, t,n,m,cas=1,x,y, z;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n,&m);
        for (int i  =0; i<n; i++)
            for (int j = 0; j<n; j++)
                graph[i][j]=inf;
        for (int i = 0; i<n; i++)
                graph[i][i] = 0,node[i]=inf;
        while(m--)
        {
            scanf("%d %d %d", &x,&y,&z);
            if(graph[x][y]>z)
            {
                graph[x][y] = z;
                graph[y][x] = z;
            }
        }
        scanf("%d", &t);
        dijkstra(n, t);
//        Floyed(n);
        printf("Case %d:\n",cas++);
        for (int i =0; i<n; i++)
        {
            if (node[i]==inf) printf("Impossible\n");
            else printf("%d\n", node[i]);
        }
    }
    return 0;
}

void dijkstra(int n, int t)
{
    node[t] = 0;
    queue<int>q;
    q.push(t);
    int now;
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        for (int i = 0; i<n; i++)
        {
            if(graph[now][i]==inf) continue;
            if(max(node[now],graph[now][i])<node[i])
            {
                node[i] = max(node[now],graph[now][i]);
                q.push(i);
            }
        }
    }
    return;
}

/*
void Floyed(int n)
{
    for (int k = 0; k<n; k++)
    {
        for (int i = 0; i<n; i++)
        {
            if(i == k||graph[i][k]==inf) continue;
            for (int j =0; j<n; j++)
            {
                if(j==k||graph[k][j]==inf) continue;
                if(graph[i][j]==inf)
                {
                    graph[i][j] =max(graph[i][k],graph[k][j]);
//                    graph[j][i] =  graph[i][j];
                }
                else
                {
                    graph[i][j] =min(max(graph[i][k],graph[k][j]),graph[i][j]);
//                    graph[j][i] =  graph[i][j];
                }

            }
        }
    }

    return;
}
/*
2

5 6
0 1 5
0 1 4
2 1 3
3 0 7
3 4 6
3 1 8
1

5 4
0 1 5
0 1 4
2 1 3
3 4 7
1
*/
