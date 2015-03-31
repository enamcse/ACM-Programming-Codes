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

#define sz 2000005
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
ll bigmod(ll sonkha,ll ghat,ll vag_const)
{
    ll vag_shesh=1;
    while(ghat>0)
    {
        if(ghat%2==1)
        {
            vag_shesh=(vag_shesh*sonkha)%vag_const;
        }
        ghat/=2;
        sonkha=(sonkha*sonkha)%vag_const;
    }
    return vag_shesh;
}
ll inverse_mod(ll bivajok, ll vag_const)
{
    return bigmod(bivajok,vag_const-2, vag_const);
}

using namespace std;

int fact[sz];

void factorial()
{
    fact[0] = 1LL;
    for (ll i = 1; i<sz; i++)
        fact[i] = (fact[i-1]*i)%mod;
    return;
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    factorial();
    int t, n, cas=1, k;
    ll ans;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &n, &k);
//        cout<<fact[ n+k-1 ]<<" > "<< fact[n]<<" & "<<fact[k-1]<<endl;
        ans = (fact[ n+k-1 ] * inverse_mod( ((ll)fact[n]*fact[k-1])%mod ,mod))%mod;
        printf("Case %d: %lld\n", cas++, ans);
    }


    return 0;
}
