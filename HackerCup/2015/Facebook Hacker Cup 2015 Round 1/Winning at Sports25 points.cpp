/**
* H:\Dropbox\Code\HackerCup\2015\Facebook Hacker Cup 2015 Round 1\Winning at Sports25 points.cpp
* Created on: 2015-01-18-12.05.22, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 2005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("winning_at_sports.txt","r",stdin)
#define fwrite freopen("output3.txt","w",stdout)
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

int dp[sz][sz], dp2[sz][sz];


int rec(int x, int y)
{
    if(x==1&&y==0) return 1;
    int &ret=dp[x][y];
    if(ret!=-1) return ret;
    ret = 0;
    if(x>y+1) ret+=(rec(x-1,y)%mod);
    ret%=mod;
    if(y>0) ret+=(rec(x,y-1)%mod);
    ret%=mod;
    return ret;
}


int rec2(int x, int y)
{
    if(x==0&&y==0) return 1;
    int &ret=dp[x][y];
    if(ret!=-1) return ret;
    ret = 0;
    if(x>0) ret+=(rec2(x-1,y)%mod);
    ret%=mod;
    if(y>x) ret+=(rec2(x,y-1)%mod);
    ret%=mod;
    return ret;
}


int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    int t, n, m, cas=1,x,y;

    scanf("%d", &t);
    clr(dp,-1);
    clr(dp2,-1);
    while(t--)
    {
        scanf("%d-%d", &x,&y);
        cout<<"Case #"<<cas++<<": "<<rec(x,y)<<" "<<rec2(y,y)<<"\n";
    }



   return 0;
}
