/**
* H:\Dropbox\Code\Codeforces\595B.cpp
* Created on: 2015-11-08-22.48.00, Sunday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 200005
#define pb push_back
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
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

ll n, m , k,  ans=1, block;

ll arr[100005];
int b[100005];

void calc(int x)
{
    ll ret = block/arr[x], lo, hi;
    if(b[x])ret++;

    lo = b[x];

    for (int i = 1; i<k; i++)
        lo*=10;
    if(b[x])lo--;
    hi = b[x]+1;

    for (int i = 1; i<k; i++)
        hi*=10;
    hi--;


//    cout<<ret<<" = "<<hi<<" - "<<lo<<endl;
    lo/=arr[x];
    hi/=arr[x];

    ret-=(hi-lo);

//    cout<<ret<<" := "<<hi<<" - "<<lo<<endl;

    ret%=mod;
//    cout<<x<<":"<<ret<<endl;
    ans = (ans*ret)%mod;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n>>k;
    for (int i = 0; i<k; i++)
        block=block*10+9;

    m = n/k;

    for (int i = 0; i<m; i++)
        cin>>arr[i];

    for (int i = 0; i<m; i++)
        cin>>b[i];

    for (int i = 0; i<m; i++)
    {
        calc(i);
    }

    cout<<ans;
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}