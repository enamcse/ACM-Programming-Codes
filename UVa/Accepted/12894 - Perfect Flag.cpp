/**
* H:\Dropbox\Code\UVa\12894 - Perfect Flag.cpp
*
* Created on: 2014-11-30-22.33.38, Sunday
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

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m,k, cas=1,r,p[6], con;

    _
    cin>>t;

    while(t--)
    {
        for (int i = 0; i<6; i++)
        cin>>p[i];
        cin>>r;
        if(r%4==0)
        {
            k=m = r/4;
            m*=9;
            k*=11;
            con = (r/2)*3;
            if(p[4]==p[0]+m&&p[5]==p[1]+con&&k+p[4]==p[2]&&con+p[5]==p[3])
                cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"NO\n";
    }

    return 0;
}
