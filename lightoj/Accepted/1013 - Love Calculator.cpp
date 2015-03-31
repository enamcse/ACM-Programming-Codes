#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>

#define clr(abc,z) memset(abc,z,sizeof(abc))
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define sz 35
#define ll long long
using namespace std;

int magnitude[sz][sz],n,m;
ll dp[sz][sz];
string s[2];

int LCS(int x, int y)
{
    if(x>=n||y>=m) return 0;
    int &ret = magnitude[x][y];
    if(ret!=-1) return ret;
    if(s[0][x]==s[1][y]) return ret = LCS(x+1,y+1)+1;
    ret = max(LCS(x+1,y),LCS(x,y+1));
    return ret;
}

ll rec(int i, int j)
{
    if(i>=n||j>=m) return 1LL;
    ll &ret = dp[i][j];
    if(ret!=-1LL) return ret;
    if(s[0][i]==s[1][j]) ret=rec(i+1,j+1);
    else if(LCS(i,j+1)==LCS(i+1,j)) ret=rec(i,j+1)+rec(i+1,j);
    else if(LCS(i,j+1)>LCS(i+1,j)) ret=rec(i,j+1);
    else ret=rec(i+1,j);
    return ret;
}

int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    int t, cas=1, ans;
    char line1[sz], line2[sz];
    scanf("%d", &t);
    while(t--)
    {
        clr(magnitude,-1);
        clr(dp,-1);
        scanf(" %s %s", line1, line2);
        s[0] = line1;
        s[1] = line2;
        n = s[0].size();
        m = s[1].size();
        ans = LCS(0,0);

        printf("Case %d: %d ",cas++, (n+m-ans));
        printf("%lld\n", rec(0,0) );
    }
    return 0;
}
