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

#define sz 155
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

vector< pair<int,int> >s;
int n, k, d;
ll ans;
ll dp[sz][sz];

ll fnd(int now, int h)
{
    if(now<0) return 0LL;
    ll &ret=dp[now][h];
    if(ret!=-1) return ret;
    ret = 0LL;
    if(now==0)
    {
        if(h>=d) return ret=1LL;
        return 0LL;
    }

    for (int i = 1; i<=k; i++)
        ret+=fnd(now-i,max(i,h));
    ret%=mod;
    return ret;
}

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    clr(dp,-1);
    int t,  m, cas=1;
    cin>>n>>k>>d;

    cout<<fnd(n,0);
    return 0;
}
