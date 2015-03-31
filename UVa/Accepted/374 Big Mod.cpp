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
#include<set>
#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

ll rec(ll x, ll y, ll mod)
{
    if(y==0) return 1;
    ll ret = rec(x,y/2,mod);
    ret*=ret;
    if(y&1) ret*= x;
    ret%=mod;
//    ret = (ret+mod)%mod;
    return ret;
}

int main()
{
    ll x, y, mod;
    while(scanf("%lld %lld %lld", &x, &y, &mod)==3)
    {
        printf("%lld\n", rec(x,y,mod));
    }
    return 0;
}
