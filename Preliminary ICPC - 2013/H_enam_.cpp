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
#define mod 4294967296
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define lim 50
using namespace std;

unsigned int fact[lim+1];

void rec()
{
    ll i;
    fact[0]=fact[1]=1;
    for (i=2; i<=lim; i++)
    {
        fact[i] = (((fact[i-1]%mod)*(i%mod))%mod);
        printf("%lld\n", fact[i]);
    }
    return;
}

int main()
{
    int t, cas=1;
    ll n, ans, i;
    scanf("%d", &t);
    rec();
    while(t--)
    {
        scanf("%lld", &n);
        if (n>lim)
        {
            printf("Case %d: 0\n", cas++, ans);
        }
        else printf("Case %d: %lld\n", cas++, fact[n]);
    }
    return 0;
}

