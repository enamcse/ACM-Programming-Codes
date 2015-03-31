//Verdict: NOT SOLVED
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

#define sz 100005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
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

ll primes[sz],cnt,factor[sz];
bool siv[sz];

map<ll,ll>mp;

void sieve()
{
    int sq = sqrt(1e9+100);
    for (int i = 3; i<=sq; i+=2)
        if(!siv[i])
            for (int j = i*i; j<sz; j+=i+i)
                siv[j]=false;

    primes[cnt++]=2;
    for (int i = 3; i<sz; i+=2)
        if(!siv[i]) primes[cnt++]=i;
    return;
}

void factorize(ll now)
{
    for (int i = 0; i<cnt; i++)
    {
        if(now%primes[i]==0)
        {
            if(factor[i]==-1) factor[i] = primes[i];
            while(now%primes[i]==0) now/=primes[i],factor[i]=(factor[i]*primes[i])%mod;
        }
    }
    if(now>1)
        if(mp[now]) mp[now]=(mp[now]*now)%mod;
        else mp[now]=(now*now)%mod;
    return;
}



int main()
{
#ifdef ENAM
//        fread;
//    fwrite;
#endif // ENAM

    sieve();
    ll ans, tew;
    int t, n, m, cas=1;

    scanf("%d", &t);

    while(t--)
    {
        clr(factor,-1);
        mp.clear();
        scanf("%d", &n);
        for (int i = 0; i<n; i++)
        {
            scanf("%d", &m);
            factorize(m);
        }
        ans = 1;

        for (map<ll,ll>::iterator it =  mp.begin(); it!=mp.end(); it++)
        {
            tew=(it->second+mod-1)%mod;
            tew = (tew*inverse_mod(it->first -1,mod))%mod;
            ans=(ans*tew)%mod;
        }

        for (int i = 0; i<cnt; i++)
        {
            if(factor[i]==-1) continue;
            tew=(factor[i]+mod-1)%mod;
            tew = (tew*inverse_mod(primes[i]-1,mod))%mod;
            ans=(ans*tew)%mod;
        }
        printf("Case %d: %lld\n", cas++, ans);
    }






    return 0;
}

