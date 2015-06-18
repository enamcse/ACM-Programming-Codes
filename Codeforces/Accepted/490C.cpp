/**
* H:\Dropbox\Code\Codeforces\490C.cpp
*
* Created on: 2014-11-23-15.00.37, Sunday
* Author: Enamul Hassan
* Verdict: SOLVED
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1000005
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


string s;
ll a, b, rem1[sz],rem2[sz],val;



int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    _

    cin>>s>>a>>b;
    int n = s.size();

    for (int i = 0; i<n; i++)
    {
        val*=10;
        val+=(s[i]-'0');
        rem1[i] = val%a;
        val%=a;
    }

    val = (s[n-1]-'0')%b;
    rem2[n-1]=val;
    for (int i = n-2; i>=0; i--)
    {
        val+=bigmod(10,n-i-1,b)*(s[i]-'0');
        rem2[i] = val%b;
        val%=b;
    }

    for (int i = 0; i<n-1; i++)
    {
        if(rem1[i]==0&&rem2[i+1]==0&&s[i+1]!='0')
        {
            cout<<"YES\n";
            cout<<s.substr(0,i+1)<<"\n"<<s.substr(i+1);
            return 0;
        }
    }
    cout<<"NO";

    return 0;
}
