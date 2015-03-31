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
#include <stack>

#define sz 1010
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
#define mod 100000007
using namespace std;

int a[50],c[50];
int dp[sz];

int coin_change(int n,int target)
{
    clr(dp,0);
    dp[0]=1;
    int mxval=0,coin,ntk;
    for (int i =0; i<n; i++)
    {
        coin = a[i];
        for (int j = mxval; j>=0; j--)
        {
            for (int p = 1; p<=c[i]; p++)
            {
                ntk=j+coin*p;
                if(dp[j]&&ntk<=target)
                {
                    dp[ntk]=(dp[ntk]+dp[j])%mod;
                    mxval=max(mxval,ntk);
                }
            }
        }
    }
    return dp[target]%mod;
}

int main()
{
    int cas=1,t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for (int i = 0; i<n; i++)
            scanf("%d",&a[i]);

        for (int i = 0; i<n; i++)
            scanf("%d",&c[i]);
        printf("Case %d: %d\n",cas++,coin_change(n,k)%mod);
    }
    return 0;
}
