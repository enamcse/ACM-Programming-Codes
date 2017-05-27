/**
* H:\Dropbox\Code\Code Jam\APAC 2015\Problem A. Googol String.cpp
* Created on: 2015-08-23-11.18.06, Sunday
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
#define fread freopen("A-large.in","r",stdin)
#define fwrite freopen("outputAlarge.txt","w",stdout)
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

int tew(ll d, ll k)
{
    if(d==0) return 0;
    if(((1LL<<(d)) - 1) == k) return 0;
    if(((1LL<<(d)) - 1) < k) return (tew(d-1,((1LL<<(d+1)) - 1) - k-1)^1);
    return tew(d-1,k);
}

int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    ll t, n, m, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>t;

    while(t--)
    {
        cin>>n;
        cout<<"Case #"<<cas++<<": "<<tew(62,n-1)<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
