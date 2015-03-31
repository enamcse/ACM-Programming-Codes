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

#define sz 1000001
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
#define mod 1000003
using namespace std;

int fact[sz];
ll last[3];

int func(ll a, ll b)
{
    ll r,q;
    q = a/b;
    r = a - b*q;

    if(r==0) return last[1];
    last[2] = last[0] - (q*last[1]);
    last[0] = last[1];
    last[1] = last[2];
    return (int)(func(b,r)%mod);
}

int main()
{
    fact[1]=fact[0]=1;

    for (int i = 2; i<sz; i++)
        fact[i]=(int)(((ll)fact[i-1]*(ll)i)%mod);

    int nCr, t, cas=1, n, k;
    int din, neu;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        din = fact[n];
        neu = (int) (((ll)fact[k]*(ll)fact[n-k])%mod);
        last[0] = 0;
        last[1] = 1;
        neu = func(mod,neu)%mod;

        if(neu<0) neu+=mod;
        nCr = (int)(((ll)din*(ll)neu)%mod);
        printf("Case %d: %d\n", cas++, nCr);
    }
	return 0;
}
