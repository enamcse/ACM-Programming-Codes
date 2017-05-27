/**
* E:\Dropbox\Code\CodeChef\Snack Down 2016\SnackDown Online elimination round\VCAKE.cpp
* Created on: 2016-06-19-20.27.24, Sunday
* Verdict: Solved
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

bool dhurhala(ll R, ll C, ll a, ll b, ll c)
{
    if(a%R==0&&b%R==0&&c%R==0&&a/R+b/R+c/R==C) return true;
    return false;
}

bool what(ll R, ll C, ll a, ll b, ll c)
{
    if(dhurhala(R,C,a,b,c)) return true;
    if(a%R!=0) return false;
    ll k = C-a/R;
    if(k<=0) return false;
    if(b%k!=0) return false;
    if(c%k!=0) return false;
     if(b/k+c/k==R) return true;
     return false;
}

int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	ll r,c,cas = 1,t,n,m,x,y,z,k,j;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>t;

    while(t--)
    {
        cin>>r>>c>>m>>k>>j;
        if(r*c!=m+k+j)
        {
            cout<<"No\n";
            continue;
        }
//        cerr<<"here"<<endl;
        if( what(r,c,m,k,j)||
            what(c,r,m,k,j)||
            what(r,c,m,j,k)||
            what(c,r,m,j,k)||
            what(r,c,j,m,k)||
            what(c,r,j,m,k)||
            what(r,c,j,k,m)||
            what(c,r,j,k,m)||
            what(r,c,k,j,m)||
            what(c,r,k,j,m)||
            what(r,c,k,m,j)||
            what(c,r,k,m,j)
           ) cout<<"Yes\n";
        else cout<<"No\n";

    }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
