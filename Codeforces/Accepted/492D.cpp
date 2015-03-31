/**
* H:\Dropbox\Code\Codeforces\492D.cpp
*
* Created on: 2014-12-02-00.10.17, Tuesday
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
vector<ll>v;
map<ll,ll>mp;
int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    _
    ll t, n, m, cas=1,x,y;
    cin>>n>>x>>y;

    for (int i = 1; i<=y; i++)
    {
        v.pb(i*x);
        mp[i*x]++;
    }

    for (int i = 1; i<=x; i++)
    {
        v.pb(i*y);
        mp[i*y]+=2;
    }
    sort(all(v));
//    cout<<v.size()<<endl;

    for (int i = 0; i<n; i++)
    {
        cin>>m;
        m%=v.size();
        if(m==0)cout<<"Both"<<endl;
        else if(mp[ v[m-1] ]>=3) cout<<"Both"<<endl;
        else if(mp[ v[m-1] ]==2) cout<<"Vanya"<<endl;
        else if(mp[ v[m-1] ]==1) cout<<"Vova"<<endl;
    }


    return 0;
}
