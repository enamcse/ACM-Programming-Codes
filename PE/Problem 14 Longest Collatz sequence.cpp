#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#define sz 1000000
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

int cycle_length (ll n);

int main()
{
    int  k, large=0, n, p=0;
    for (k = 837799; k < sz; k++)
    {
        n = cycle_length(k);
        cout<<k<<" is "<<n<<endl;
        if (n > large)
        {
            large = n;
            p =k;
        }
    }

    cout<<p<<"::"<<large<<endl;

    return 0;
}

int cycle_length(ll x)
{
    ll i;
    if(x != 1)
    {
        for (i = 1; x != 1; ++i)
        {
            if (x % 2 == 1) x = (3 * x + 1);
            else x = x / 2;
//            cout<<x<<" here"<<endl;
        }
    }
    else i = 1;
    return i;
}
