/**
* H:\Dropbox\Code\Codeforces\510D.cpp
* Created on: 2015-02-03-04.07.28, Tuesday
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
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int l[305], c[305], n, cnt=1;

map< int, int>mp;

int dp[305][4000];

int rec(int pos, int gcd)
{
    if(gcd==1) return 0;
    if(pos==n)
    {
        if(gcd==1) return 0;
        return inf;
    }
    if(mp.find(gcd)==mp.end()) mp[gcd]=cnt++;

    int &ret = dp[pos][ mp[gcd] ];
    if(ret!=-1) return ret;
    ret = inf;
    ret = min(ret,rec(pos+1,__gcd(gcd,l[pos]))+c[pos]);
    ret = min(ret,rec(pos+1,gcd));
    return ret;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    _

	cin>>n;

	for (int i = 0; i<n; i++)
	    cin>>l[i];
	for (int i = 0; i<n; i++)
	    cin>>c[i];
    clr(dp,-1);

	int ans = rec(0,0);

    if(ans==inf) cout<<-1;
    else cout<<ans;

   return 0;
}
