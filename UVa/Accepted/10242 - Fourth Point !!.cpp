/**
* H:\Dropbox\Code\UVa\10242 - Fourth Point !!.cpp
* Created on: 2015-01-25-06.06.26, Sunday
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
#define EPS 1e-3
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
_
    int t, n, m, cas=1;
	double x[4],y[4];
	while(cin>>x[0]>>y[0])
    {
        for (int i = 1; i<4; i++)
            cin>>x[i]>>y[i];
//        assert(abs(x[1]-x[2])<EPS&& abs(y[1]-y[2])<EPS);
        if(x[0]==x[2] && y[0]==y[2])
        {
            swap(x[0], x[1]);
            swap(y[0], y[1]);
        }
        else if(x[0]==x[3] && y[0]==y[3])
        {
            swap(x[0], x[1]);
            swap(y[0], y[1]);
            swap(x[2], x[3]);
            swap(y[2], y[3]);
        }
        else if(x[1]==x[3] && y[1]==y[3])
        {
            swap(x[2], x[3]);
            swap(y[2], y[3]);
        }
        cout<<setprecision(3)<<fixed<<x[0]+x[3]-x[2]<<" "<<y[3]-y[1]+y[0]<<"\n";
    }
   return 0;
}
