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

int grid[sz][sz],last,n, dp[sz][(1<<sz)];

int rec(int stdnt, int mask)
{
    if(mask == last)
    {
        int len=0;
        return len;
    }
    int &ret = dp[stdnt][mask];
    if(ret!=-1) return ret;
    ret = 0;

    for (int i =0; i<n; i++)
    {
        if((mask&(1<<i))==0) ret=max(ret,grid[stdnt][i]+rec(stdnt+1,(mask|(1<<i))));
    }
    return ret;
}

int main()
{
    _
    int t,cas=1,mn;
    scanf("%d",&t);

    while(t--)
    {
        clr(dp,-1);
        scanf("%d",&n);
        for (int i = 0; i<n; i++)
            for (int j = 0; j<n; j++)
                scanf("%d",&grid[i][j]);
        mn = 0;
        last = (1<<n)-1;
        for (int i = 0; i<n; i++)
        {
            mn = max(mn,rec(1,(1<<i))+grid[0][i]);
        }
        printf("Case %d: %d\n",cas++,mn);
    }
    return 0;
}
