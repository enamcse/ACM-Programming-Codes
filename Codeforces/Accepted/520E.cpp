/**
* H:\Dropbox\Code\Codeforces\520E.cpp
* Created on: 2015-05-17-18.34.35, Sunday
* Verdict: Solved
* Author: Enamul Hassan
* Clue: Construct the n^2 solution which is summation of summation.
*       Observe and swap the inner and outer summation. I summation
*       could easily be gained by cumulative sum. Tutorial could show details.
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 100005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
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

ll pow10[sz], fact[sz];
int cumsum[sz];
string s;

ll nCr(int n, int r)
{
    if(n<r) return 0LL;
    ll now = fact[n]%mod;
    now = (now*inverse_mod(fact[r],mod))%mod;
    now = (now*inverse_mod(fact[n-r],mod))%mod;
    return now;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,k;
    ll ans=0, now;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    cin>>n>>k>>s;
    pow10[0] = 1;
    fact[0] = 1;
    for (int i = 1; i<=n; i++)
    {
        pow10[i]=(pow10[i-1]*10LL)%mod;
        fact[i]=(fact[i-1]*i)%mod;
    }

    cumsum[0]=s[0]-'0';
    for (int i = 1; i<n; i++)
        cumsum[i]=( cumsum[i-1] + s[i] - '0');

    for (int i = 0; i<n-1; i++)
    {
        now = pow10[i];
        now = (now*cumsum[n-i-2])%mod;
        now = (now*nCr(n-i-2, k-1))%mod;

        ans = (ans+now)%mod;
    }

    for (int i = 0; i<n; i++)
    {
        now=((s[i]-'0')*pow10[n-1-i]);
        now = (now * nCr(i,k))%mod;
        ans = (now+ans)%mod;
    }

    cout<<ans;
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
