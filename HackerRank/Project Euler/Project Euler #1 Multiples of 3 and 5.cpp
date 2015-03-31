#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

int main()
{
    ll a, n, sum, nth;
    int t;
    cin>>t;

    while(t--)
    {
        cin>>n;
        n--;
        nth = n/3;
        sum=(3*nth*(nth+1))/2;
        nth = n/5;
        sum+=(5*nth*(nth+1))/2;
        nth = n/15;
        sum-=(15*nth*(nth+1))/2;
        cout<<sum<<endl;
    }

    return 0;
}
