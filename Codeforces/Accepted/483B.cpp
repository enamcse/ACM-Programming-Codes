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

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1LL<<50)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

ll a,b,x,y, ans=2, l,r,mid;

bool check(ll c)
{
    ll i,j,k,n,m,ok;
    i = c/x;
    j = c/y;
    k = c/(x*y);
    n = j-k;
    m = i-k;
    ok=c-i-j+k;
    if(n<a)ok-=(a-n);
    if(ok<0) return false;
    ok-=(b-m);
    return ok>=0;
}

int main()
{

    cin>>a>>b>>x>>y;

    l=1,r=inf;

    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))
        {
            ans = mid;
            r=mid-1;
        }
        else l = mid+1;
    }

    cout<<ans;


    return 0;
}
