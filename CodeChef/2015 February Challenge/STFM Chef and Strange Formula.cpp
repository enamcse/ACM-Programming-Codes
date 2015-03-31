/**
* H:\Dropbox\Code\CodeChef\2015 February Challenge\STFM Chef and Strange Formula.cpp
* Created on: 2015-02-09-00.12.27, Monday
* Verdict: Solved
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

int arr[10000100];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    ll x,ans=0, y, now;
    _

	cin>>n>>m;
    arr[0]=1;
    for (ll i = 1; i<=m; i++)
        arr[i]=(arr[i-1]*i)%m;
    for (ll i = 1; i<=m; i++)
        arr[i]=(arr[i]*i)%m;

    for (ll i = 2; i<=m; i++)
    {
        arr[i]+=arr[i-1];
        arr[i]%=m;
    }


    for (int i = 0; i<n; i++)
    {
        cin>>x;

        now = y = x;
        y++;
        if(x%2) y>>=1;
        else x>>=1;

        ans+=(((((now%m)*(x%m))%m)*(y%m))%m);
        ans%=m;

        if(now>m) ans=(ans+arr[m])%m;
        else ans=(ans+arr[now])%m;
    }

    cout<<ans;


   return 0;
}
