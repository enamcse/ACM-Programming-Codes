/**
* H:\Dropbox\Code\Codeforces\492C.cpp
*
* Created on: 2014-12-01-23.02.38, Monday
* Author: Enamul Hassan
* Verdict: NOT SOLVED
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

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
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

vector< pair<ll,ll> >v;

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    ll t, n, m,r,avg, cas=1, total, now, ans,a,b;

    cin>>n>>r>>avg;
    total = n*avg;
    ans=0;
    now=0;
    for (ll i = 0; i<n; i++)
    {
        cin>>a>>b;
        now+=a;
        v.pb( make_pair(b,a) );
    }
    sort(all(v));
    vector< pair<ll,ll> >::iterator it = v.begin();
    while(now<total)
    {
        pair<ll,ll> ppp = *it;
        ll to = ppp.second;
        if((r - to+now)<total)
        {
            ans+=(r - to)*(ppp.first);
            now+=(r-to);
        }
        else
        {
            ans+=(total - now)*(ppp.first);
            now=total;
        }
        it++;
    }
    cout<<ans<<endl;

    return 0;
}
