#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 16
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int dp[sz][(1<<sz)],n,last, dist[sz][sz];

vector<int>p,q;

int rec(int pos, int mask)
{
    if(mask==last) return 0;
    int &ret = dp[pos][mask];
    if(ret!=-1) return ret;
    ret = inf;
    for (int i = 0; i<n; i++)
    {
        if(((1<<i)&mask)==0)
        {
            ret = min(ret,dist[pos][i]+rec(i,((1<<i)|mask)));
        }
    }
    return ret;
}


int main()
{
    _
    int t, cas=1,x, y;
    scanf("%d", &t);

    while(t--)
    {
        p.clear();
        q.clear();
        clr(dp,-1);
        scanf("%d", &n);
        last = (1<<n)-1;
        for (int i  =0 ;i<n; i++)
        {
            scanf("%d %d", &x, &y);
            p.pb(x);
            q.pb(y);
        }
        for (int i =0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                x = abs(p[i] - p[j]);
                y = abs(q[i] - q[j]);
                dist[i][j] = max(x,y);
            }
        }
        x = inf;
        for (int i = 1; i<n; i++)
        {
            x = min(x,rec(i,(1<<i))+dist[0][i]);
        }
        printf("Case %d: %d\n",cas++,x);
    }

    return 0;
}
