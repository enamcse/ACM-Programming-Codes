/**
* H:\Dropbox\Code\lightoj\1276 - Very Lucky Numbers.cpp
* Created on: 2015-02-01-05.42.59, Sunday
* Verdict: Solved
* Comment: This code gives Runtime Error while using cin/cout with sync.
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
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
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

vector<ll>v,vv,vvv;
ll hh = 1e12;
int len;
map<ll,bool>mpp;
void rec(int pos, ll prod)
{
    if(prod>hh || pos>=len) return;
    mpp[prod]=true;
    ll now;
    for (int i = pos; i<len; i++)
    {
        if(log10(prod)+log10(v[i]) > 12) break;
        now = prod*v[i];
        if(now>hh) break;
        rec(i,now);
    }

}

void pre()
{
    v.pb(4);
    v.pb(7);
    vvv = v;
    for (int i = 1; i<12; i++)
    {
        vv = vvv;
        vvv.clear();
        for (vector<ll>::iterator it = vv.begin(); it!=vv.end(); it++)
        {
            ll now = *it;
            v.pb(now * 10 + 4);
            v.pb(now * 10 + 7);
            vvv.pb(now * 10 + 4);
            vvv.pb(now * 10 + 7);
        }
    }

    len = v.size();
    vv.clear();
    vvv.clear();
}

void post()
{
    v.clear();
    for (map<ll,bool>::iterator it = mpp.begin(); ++it!=mpp.end();)
        v.pb(it->first);
    sort(all(v));
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1, ans;
//    _
    ll a, b;
    pre();
    rec(0,1);
    post();

    cin>>t;

    while(t--)
    {
//        cin>>a>>b;
        scanf("%lld %lld", &a, &b);
        ans = upper_bound(all(v), b) - lower_bound(all(v), a);
//        cout<<"Case "<<cas++<<": "<<ans<<"\n";
        printf("Case %d: %d\n", cas++,ans);
    }

   return 0;
}
