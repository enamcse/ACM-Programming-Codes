#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MX = 111;

int N, M, X[MX], Y[MX], dp[MX][MX];

/**
    Solution : (n^3) Dynamic Programming
*/

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T ;
    scanf("%d",&T);
    for(int cs = 1 ; cs <= T ; cs++ ){
        memset(dp,0,sizeof dp);
        scanf("%d %d",&N,&M);

        for( int i = 1 ; i <= M ; i++ )
            scanf("%d %d",&X[i],&Y[i]);

        for( int i = X[1] ; i <= Y[1] ; i++ ) dp[1][i] = 1;

        for( int i = 2 ; i <= M ; i++ )
            for( int j = 0 ; j <= N ; j++ )
                for( int k = X[i] ; k <= Y[i] ; k++ )
                    if( j - k >= 0 )
                        dp[i][j] = ( dp[i][j] + dp[i-1][j-k] ) % MOD ;

        printf("Case %d: %d\n",cs,dp[M][N]);
    }
}
