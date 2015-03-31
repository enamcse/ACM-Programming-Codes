#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include<set>

#define sz 1000
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int  node[sz], avg,n;
bool grid[sz][sz],col[sz],flag;

void bfs(int x)
{
    if(col[x]||flag==false) return;
    col[x]=true;
    queue<int>q;
    q.push(x);
    int sum=0, p=0;
    while(!q.empty())
    {
        x = q.front();
        sum+=node[x];
        p++;
        q.pop();
        for (int i =0; i<n; i++)
        {
            if(col[i]) continue;
            if(grid[x][i])
            {
                q.push(i);
                col[i] = true;
            }
        }
    }
    if(sum%p) flag = false;
    else if(avg!=sum/p) flag = false;
    return;
}

int main()
{
    int t, m,cas=1,ans, x,y;
    scanf("%d", &t);
    while(t--)
    {
        clr(col,false);
        clr(grid,false);
        flag=true;
        ans=0;
        scanf("%d %d", &n, &m);
        for (int i =0; i<n; i++)
        {
            scanf("%d", &node[i]);
            ans+=node[i];
        }
        for (int i = 0; i<m; i++)
        {
            scanf("%d %d", &x, &y);
            grid[x-1][y-1] = true;
            grid[y-1][x-1] = true;
        }
        if(ans%n) printf("Case %d: No\n", cas++);
        else
        {
            avg = ans/n;
            for (int i = 0; i<n; i++)
                bfs(i);
            if(flag)printf("Case %d: Yes\n", cas++);
            else printf("Case %d: No\n", cas++);
        }
    }
	return 0;
}
