#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1010
#define inf (1<<30-1)

using namespace std;

int rr[]={0,0,-1,1};
int cc[]={-1,1,0,0};

int graph[sz][sz], weight[sz][sz];

int n,m;

struct data{
    int x,y;

    bool operator <(const data &p)const
    {
        return weight[x][y]>weight[p.x][p.y];
    }
};

void init()
{
    for (int i = 0; i<=n; i++)
        for (int j = 0; j<=m; j++)
            weight[i][j]=inf;
    return;
}


void dijkstra()
{
    weight[0][0]=graph[0][0];
    m--,n--;
    priority_queue<data>pq;
    data v,u;
    v.x=v.y=0;
    pq.push(v);
    while(!pq.empty())
    {
        u = pq.top();
        int cost = weight[u.x][u.y];
        pq.pop();
        for (int i = 0; i<4; i++)
        {
            v.x = u.x+rr[i];
            v.y = u.y+cc[i];

            if((v.x>=0&&v.y>=0)&&(v.x<=n&&v.y<=m)&&(weight[v.x][v.y]>cost+graph[v.x][v.y]))
            {
                weight[v.x][v.y]=cost+graph[v.x][v.y];
                pq.push(v);
            }
        }
    }

//    for (int i =0; i<=n; i++)
//    {
//        for (int j =0; j<=m; j++)
//            cout<<weight[i][j]<<" ";
//        cout<<endl;
//    }

    return ;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m; j++)
                scanf("%d",&graph[i][j]);
        }
        init();
        dijkstra();
        printf("%d\n",weight[n][m]);
    }
	return 0;
}
