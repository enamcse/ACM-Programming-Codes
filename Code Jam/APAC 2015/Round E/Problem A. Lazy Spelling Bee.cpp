/**
* E:\Dropbox\Code\Code Jam\APAC 2015\Round E\Problem A. Lazy Spelling Bee.cpp
* Created on: 2016-01-31-11.14.16, Sunday
* Verdict: Not Solved
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
#define csco cout<<"Case #"<<cas++<<": ";
#define mod 1000000007

#ifdef ENAM
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...)
#endif

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int n;
string s;

int dp[1005][27][27];

int rec(int pos, int c1,int c2)
{
    if(pos==n) return 1;
    int &ret = dp[pos][c1][c2];
    cerr<<pos<<" "<<c1<<" "<<c2<<" "<<ret<<endl;
    if(~ret) return ret;

    ret = 0;
    if(s[pos]-'a'==c1 || s[pos]-'a' == c2)
    {
        for(int i = 0; i<26; i++, ret%=mod)
            ret+=rec(pos+1,i,c1);
    }
    else
    {
        ret+=rec(pos+1,s[pos]-'a', c1);
        ret%=mod;
    }
    return ret;
}

int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	int t,cas=1;

    cin>>t;
    cin.ignore();
    while(t--)
    {
        clr(dp,-1);
        cin>>s;
        n = s.size();
        csco
        cout<<rec(0,26,26)%mod<<"\n";
    }
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}