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

#define sz 30099
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
#define EPS 1e-9
using namespace std;

int coin[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};

ll dp[sz];

ll coin_change(int n,int target)
{
    if(dp[target]) return dp[target];
    for (int i = 0,j; i<n; i++)
    {
        j = coin[i];
        while(j<=target)
        {
            dp[j]+=dp[(j - coin[i])];
            j++;
        }
    }
    return dp[target];
}

int main()
{
    double in;
    int n;
    clr(dp,0);
    dp[0]=1;
    coin_change(11,30000);
    while(~scanf("%lf", &in))
    {
        in+=EPS;
        n = in*100;
        if(!n) break;
        printf("%6.2lf%17lld\n",in, coin_change(11,n));
    }
	return 0;
}
