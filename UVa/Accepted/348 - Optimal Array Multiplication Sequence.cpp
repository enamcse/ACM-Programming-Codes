#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>


#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

int dp[sz][sz], path[sz][sz], p[sz+1];

int MCM(int i, int j)
{
    if(i==j) return 0;
    dp[i][j] = inf;
    int q;
    for (int k = i; k<j; k++)
    {
        q = MCM(i,k) + MCM(k+1,j) + p[i]*p[k+1]*p[j+1];
        if(q<dp[i][j])
        {
            dp[i][j] = q;
            path[i][j] = k;
        }
    }
    return dp[i][j];
}

void print_order(int i, int j)
{
    if(i==j) printf("A%d",i+1);
    else
    {
        printf("(");
        print_order(i,path[i][j]);
        printf(" x ");
        print_order(path[i][j]+1,j);
        printf(")");
    }
}

int main()
{
    int n,cas=1;
    while(scanf("%d", &n)==1&&n)
    {
        scanf("%d %d", &p[0], &p[1]);
        for (int i = 1; i<n; i++)
            scanf("%*d %d", &p[i+1]);
        MCM(0,n-1);
        printf("Case %d: ",cas++);
        print_order(0,n-1);
        printf("\n");
    }
	return 0;
}
