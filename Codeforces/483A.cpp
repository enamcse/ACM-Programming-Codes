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
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int main()
{
    ll n, a, b, c, l, r;
    cin>>l>>r;

    for (ll x = l; x<=r; x++)
        for (ll y = x+1; y<=r;y++ )
            for (ll z = y+1; z<=r; z++)
            {
                if(x==z||y==z||x==y) continue;
                if(__gcd(x,y)==1&&__gcd(y,z)==1&&__gcd(x,z)!=1)
                {
                    vector<ll>v;
                    v.pb(x);
                    v.pb(y);
                    v.pb(z);
                    sort(v.begin(), v.end());

                    cout<<v[0]<<' '<<v[1]<<' '<<v[2];
                    return 0;
                }
            }

    cout<<"-1";

    return 0;
}
