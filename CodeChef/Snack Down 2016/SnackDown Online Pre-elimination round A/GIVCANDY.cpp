/**
* E:\Dropbox\Code\CodeChef\Snack Down 2016\SnackDown Online Pre-elimination round A\GIVCANDY.cpp
* Created on: 2016-06-04-22.08.53, Saturday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((ll)a.size())
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
#define csco cout<<"Case "<<cas++<<": ";
#define mod 1000000007

#ifdef ENAM
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...)
#endif

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;
ll EGCD(ll a,ll b,ll &X,ll &Y)
{
    if(b==0)
    {
        X=1;
        Y=0;
        return a;
    }
    ll x=-(a/b),PX,r;
    r=EGCD(b,a%b,X,Y);
    PX=X;
    X=Y;
    Y=(Y*x)+(PX);
    return r;
}

vector<pair<ll,ll> > find_any_solution(ll a,ll b,ll c)
{
    ll x0,y0,x,y;
    ll g=EGCD(a,b,x0,y0);
    if(c%g) return vector<pair<ll,ll> >();
    vector<pair<ll,ll> > retSol;
    x=(c/g)*x0;
    y=(c/g)*y0;
    retSol.pb(make_pair(x,y));
    return retSol;
}
int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	ll a,b,c,d,cas = 1,t,n,m,x,y,z, ans;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        vector<pair<ll,ll>> p = find_any_solution(c,-d,b-a);
        pair<ll,ll> ppp = p[0];
        cout<<(c*ppp.first+a - d*ppp.second-b)<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
