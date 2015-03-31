#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 600
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int dir[4][2] = {-1,0,1,0,0,-1,0,1};//move in 4-direction

char grid[sz][sz];
int n, m, q;
int col[sz][sz];
struct data{
    int a,b;
    data(int p, int q)
    {
        a = p;
        b = q;
    }
};

int bfs(int x, int y)
{
    if(col[x][y]) return col[x][y];
    int cost=0, u, v;
    queue<data>p,q;
    q.push(data(x,y));
    p.push(data(x,y));
    col[x][y] = 1;
    while(!q.empty())
    {
        x = q.front().a;
        y = q.front().b;

//        cout<<x<<" "<<y<<endl;
        q.pop();
        if(grid[x][y]=='C') cost++;
        for (int i = 0; i<4; i++)
        {
            u = x+dir[i][0];
            v = y+dir[i][1];
            if(u<0||v<0||u>=n||v>=m||grid[u][v]=='#'||col[u][v]) continue;
            q.push(data(u,v));
            p.push(data(u,v));
            col[u][v] = 1;
        }
    }
    while(!p.empty())
    {
        x = p.front().a;
        y = p.front().b;
        col[x][y] = cost;
        p.pop();
    }
    return cost;
}

int main()
{
    _
    int t,cas=1, a, b;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &n, &m, &q);
        clr(col,0);
        for (int i = 0; i<n; i++)
            scanf("%s", grid[i]);
        printf("Case %d:\n", cas++);
        for (int i = 0; i<q; i++)
        {
            scanf("%d %d", &a, &b);
            printf("%d\n", bfs(a-1,b-1));
        }
    }
    return 0;
}
/*
1
4 5 2
..#..
.C#C.
##..#
..C#C
1 1
4 1
*/
