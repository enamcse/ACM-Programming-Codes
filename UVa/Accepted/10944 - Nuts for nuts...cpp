#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include<set>

#define sz 16
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<28-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int dist[sz][sz],sx,sy,len, dp[sz][(1<<sz)], dist_o[sz];
char graph[21][21];
vector<int>x,y;

int rec(int pos, int mask)
{
    if(mask==((1<<len)-1)) return dist_o[pos];
    int &ret = dp[pos][mask];
    if(ret!=-1) return ret;
    ret = inf;
    for (int i = 0; i<len; i++)
    {
        if((mask&(1<<i))==0)
            ret = min(ret,rec(i,mask|(1<<i))+dist[pos][i]);
    }
    return ret;
}

int main()
{
    int n,m, p,q,mn;
    while(scanf("%d %d", &n, &m)==2)
    {
        for (int i = 0; i<n; i++)
            scanf("%s", graph[i]);
        clr(dist,0);
        clr(dp,-1);
        x.clear();
        y.clear();
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m; j++)
            {
                if(graph[i][j]=='L')
                {
                    sx = i;
                    sy = j;
                }
                else if (graph[i][j]=='#')
                {
                    x.pb(i);
                    y.pb(j);
                }
            }
        }
        len = x.size();

        for (int i = 0; i<len; i++)
        {
            for (int j = 0; j<len; j++)
            {
                p = abs(x[i] - x[j]);
                q = abs(y[i] - y[j]);
                dist[i][j] = max(p,q);
            }
        }
        for (int i =0; i<len; i++)
        {
                p = abs(x[i] - sx);
                q = abs(y[i] - sy);
                dist_o[i] = max(p,q);
        }
        mn = inf;
        for (int i = 0; i<len; i++)
        {
            mn = min(mn, rec(i,(1<<i))+dist_o[i]);
        }
        if(mn!=inf) printf("%d\n", mn);
        else printf("0\n");
    }
    return 0;
}
