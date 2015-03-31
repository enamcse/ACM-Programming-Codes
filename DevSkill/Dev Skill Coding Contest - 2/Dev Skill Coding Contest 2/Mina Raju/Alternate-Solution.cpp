#include <bits/stdc++.h>
using namespace std;
int dp[1000+10][3];
vector <int> V[2];
void Reset()
{
    V[0].clear();
    V[1].clear();
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T ;
    scanf("%d",&T);
    while( T-- )
    {
        Reset();
        int R , n , m ;
        scanf("%d%d%d",&R,&n,&m);

        for(int i=1;i<=n;i++)
        {
            int a ;
            scanf("%d",&a);
            V[0].push_back(a);
        }
        for(int i=1;i<=m;i++)
        {
            int a ;
            scanf("%d",&a);
            V[1].push_back(a);
        }

        for(int i=1;i<=R;i++)
        {
            for(int j=0;j<=1;j++)
            {
                dp[i][j] = false ;
                for(int k=0;k<V[j].size();k++)
                {
                    if(i-V[j][k]>=0&&dp[i-V[j][k]][!j]==false) dp[i][j] = true ;
                }
            }
        }

        if(dp[R][0]) puts("Mina wins");
        else puts("Raju wins");
    }
    return 0;
}
