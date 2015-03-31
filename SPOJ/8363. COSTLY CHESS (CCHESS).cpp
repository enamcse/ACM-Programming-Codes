#include <iostream>
#include <stdio.h>
#include <queue>

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)

int knight[8][2] = {-1,-2,-2,-1,-1,2,-2,1,1,-2,2,-1,1,2,2,1};//knight moves
using namespace std;

int grid[8][8];
int a,b,c,d;

struct data {
    int s, e, cost;
    bool operator < (const data &x) const
    {
        return cost > x.cost;
    }
    data (int a, int b, int c)
    {
        s = a;
        e = b;
        cost = c;
    }
};

int dijkstra()
{
    int x,y, cost=0, u, v, cc;
    priority_queue<data>p;
    p.push(data(a,b,cost));
    grid[a][b] = 0;
    while(!p.empty())
    {
        x = p.top().s;
        y = p.top().e;
        cost = p.top().cost;
        p.pop();
        if(x==c&&y==d) return grid[c][d];
        for (int i =0; i<8; i++)
        {
                u = x+knight[i][0];
                v = y+knight[i][1];
                if(u<0||v<0||u>=8||v>=8) continue;
                cc = u*x+y*v;
                if(cc+cost<grid[u][v])
                {
                    grid[u][v] = cc+cost;
                    p.push(data(u,v,grid[u][v]));
                }
        }
    }
    return -1;
}

int main()
{

    while(scanf("%d %d %d %d", &a, &b, &c, &d)==4)
    {
        for (int i = 0; i<8; i++)
            for (int j = 0; j<8; j++)
                grid[i][j]=inf;
        printf("%d\n",dijkstra());
//        for (int i = 0; i<8; i++)
//        {
//            for (int j =0; j<8; j++)
//                if(grid[i][j]!=inf)cout<<grid[i][j]<<" ";
//                else cout<<"N ";
//            cout<<endl;
//        }
    }
    return 0;
}
