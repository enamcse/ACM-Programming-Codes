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

#define sz 50005
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

int primes[78600];
bool prime[1000050];

int cnt;
void seive()
{
    int sq = sqrt(1000020);
    for (int i = 3; i<=sq; i+=2)
        if(!prime[i])
        {
            for (int j = i*i; j<=1000020; j+=i+i)
                prime[j]=true;
        }

    primes[cnt++]=2;

    for (int i = 3; i<1000020; i+=2)
        if(!prime[i]) primes[cnt++] = i;

    return;
}


int col[78600];
int t, n, mx,  st, now;


vector<int>v[1000020];

inline void kormu(int now, int id)
{
    int i = 0;
    int sc = 0, sq = sqrt(now), lakka = now;
    int nn = v[now].size();
    if(!nn)
    {
        while(primes[i]<=sq)
        {
            if(now%primes[i]==0)
            {
                v[lakka].pb(i);
                if(col[i]>=st) sc=max(sc,col[i]);
                col[ i ] = id;
                while(now%primes[i]==0) now/=primes[i];
            }
            i++;
        }
        if(now>1)
        {
            i = lower_bound(primes, primes+cnt, now) - primes;
            v[lakka].pb(i);
            if(col[i]>=st) sc=max(sc,col[i]);
            col[ i ] = id;
        }
    }
    else
    {
        for (int i = 0; i<nn; i++)
        {
            if(col[ v[now][i] ]>=st) sc=max(sc,col[ v[now][i] ]);
            col[ v[now][i] ] = id;
        }
//        cout<<"@"<<sc<<endl;
    }

    if(sc) st=sc;

    return;
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM


    seive();

    scanf("%d", &t);

    while(t--)
    {
        mx=st=0;
        clr(col,-1);
        scanf("%d", &n);

        for (int i = 1; i<=n; i++)
        {
            scanf("%d", &now);
            if(now!=1) kormu(now, i);
            mx = max(mx,i-st);
        }

        if(mx<=1) printf("-1\n");
        else printf("%d\n", mx);

    }


    return 0;
}
