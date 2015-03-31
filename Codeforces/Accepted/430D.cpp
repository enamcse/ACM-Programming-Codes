//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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
#include <set>
#include <string>
#include <stack>
#include <bitset>

#define sz 1005
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

int dp[4][sz][sz], data[sz][sz];

int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM
    int n, m, mx = 0;

    scanf("%d %d", &n, &m);

    for (int i = 1; i<=n; i++)
        for (int j  = 1; j<=m; j++)
            scanf("%d", &data[i][j]);

    //Iahub comes from starting point
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=m; j++)
            dp[0][i][j] = data[i][j] + max(dp[0][i-1][j], dp[0][i][j-1]);

    //Iahub comes from ending point
    for (int i = n; i>0; i--)
        for (int j = m; j>0; j--)
            dp[1][i][j] = data[i][j] + max(dp[1][i+1][j], dp[1][i][j+1]);

    //Iahubina comes from starting point
    for (int i = 1; i<=n; i++)
        for (int j = m; j>0; j--)
            dp[2][i][j] = data[i][j] + max(dp[2][i-1][j], dp[2][i][j+1]);

    //Iahubina comes from ending point
    for (int i = n; i>0; i--)
        for (int j = 1; j<=m; j++)
            dp[3][i][j] = data[i][j] + max(dp[3][i+1][j], dp[3][i][j-1]);

    // calculating  the best path at every point where both can meet one of two ways
    // the most outer rectangle is omitted because of avoiding ambiguity
    for (int i = 2; i<n; i++)
        for (int j  = 2; j<m; j++)
            mx = max(mx, max(dp[0][i-1][j] + dp[1][i+1][j] + dp[2][i][j+1] + dp[3][i][j-1],dp[0][i][j-1] + dp[1][i][j+1] + dp[2][i-1][j] + dp[3][i+1][j]));
    printf("%d", mx);

    return 0;
}
