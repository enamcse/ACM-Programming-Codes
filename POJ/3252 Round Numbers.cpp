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

#define sz 50005
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

ll n;

ll dp[35][2][35][35];

ll rec(int pos, bool max_flag, int one, int zero, bool flag)
{
    if(pos==33)
    {
        if(zero>=one&&flag) return 1;
        else return 0;
    }
    ll &ret = dp[pos][max_flag][one][zero];
    if(ret!=-1) return ret;
    ret = 0;
    int cond = max_flag?((n&(1<<(32-pos)))?1:0):1;

    for (int i = 0; i<=cond; i++)
    {
        ret+=rec(pos+1,max_flag&&i==cond,i?one+1:one, flag?(i?zero:zero+1):0, flag|i);
    }
    return ret;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    ll t, a, b, cas=1;
    clr(dp,-1);
    scanf("%lld %lld", &a, &b);

    a--;
    t=0;

    for (; t<33; t++)
        if(a&(1LL<<(32-t))) break;
    n = a;
    a=rec(t,1,0,0,0);

    clr(dp,-1);
    t=0;

    for (; t<33; t++)
        if(b&(1LL<<(32-t))) break;
    n = b;

    b=rec(t,1,0,0, 0);

    cout<<b-a<<endl;
    return 0;
}
