/**
* H:\Dropbox\Code\Codeforces\515B.cpp
* Created on: 2015-02-18-02.46.37, Wednesday
* Verdict: Not Solved
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

bool gg[100], bb[100];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, g ,b, p;
    _


	cin>>n>>m;
	cin>>b;

	for (int i = 0; i<b; i++)
    {
        cin>>p;
        bb[p] = true;
    }

    cin>>g;
    for (int i = 0; i<g; i++)
    {
        cin>>p;
        gg[p] = true;
    }
    p = max(n,m);
    p*=p;
    for (int i = 0; i<p; i++)
    {
        if(bb[i%n]|gg[i%m])
        {
            bb[i%n] = gg[i%m] = true;
        }
    }

    bool flag=true;

    for (int i = 0; i<n; i++)
        if(!bb[i]) flag = false;

    for (int i = 0; i<m; i++)
        if(!gg[i]) flag = false;

    if(flag) cout<<"Yes";
    else cout<<"No";

   return 0;
}
