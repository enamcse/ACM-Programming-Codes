#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#define sz 100000
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

ll v[sz];

int main()
{
    ll n=0, ind, fact=0, k, mx=0;

    for (ll i = 1; i<=sz; i++)
    {
        n+=i;
        v[i-1] = n;
    }
    ind = sz-1;
//    k = v[ind];

//    for (int i = 0; i<7; i++)
//        cout<<v[i]<<endl;

//    cout<<k<<endl;
    for (ll j = 12374; j<=ind; j++)
    {
       k = v[j];
       fact =0;
        for (ll i = 1; i<=k; i++)
            if(!(k%i)) fact++;
//        cout<<fact<<endl;
//        mx = mx>fact?mx:fact;
//        cout<<j<<" "<<fact<<endl;
        if(fact>500)
        {
            cout<<k<<endl;
            break;
        }
    }
//    cout<<mx<<endl;
    return 0;
}
