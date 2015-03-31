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
#define sz 20010
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

vector<int>adj[sz];

bool col[sz];
int m[sz];
int cnt, zero[2], vis[sz];

void bfs(int x)
{
    int now,c = 0, len;
    queue<int>q;
    q.push(x);
    vis[x] = 0;
    col[x] = true;
    zero[ c ]++;
    while(!q.empty())
    {
        x = q.front();
        c = (1^vis[x]);
        len = adj[x].size();
        for (int i = 0; i<len; i++)
        {
            now = adj[x][i];
            if(col[now]) continue;
            col[now] = true;
            vis[now] = c;
            zero[ c ]++;
            q.push(now);
        }
        q.pop();
    }
    return;
}


int main()
{
    int t,n,x,y, p,q, k,cas=1;
    scanf("%d", &t);
    while(t--)
    {
        cnt = 0;
        clr(m,-1);
        scanf("%d", &n);
        for (int i = 0; i<n; i++)
        {
            scanf("%d %d",&x, &y);

            if(m[x]==-1)
            {
                p = m[x] = cnt++;
            }
            else p = m[x];

            if(m[y]==-1)
            {
                q = m[y] = cnt++;
            }
            else q = m[y];

            adj[p].pb(q);
            adj[q].pb(p);
        }
        k = 0;
        for (int i = 0; i<cnt; i++)
        {
            zero[1] = 0;
            zero[0] = 0;
            if(!col[i])
            {
                bfs(i);
                k+=max(zero[1],zero[0]);
            }
        }
        printf("Case %d: %d\n",cas++,k);

        for (int i = 0; i<cnt; i++)
            adj[i].clear(), col[i]=false;
    }
    return 0;
}


