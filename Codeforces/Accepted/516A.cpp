/**
* H:\Dropbox\Code\Codeforces\516A.cpp
* Created on: 2015-02-17-22.31.10, Tuesday
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

string s;

int primes[] = {2,3,5,7};
int factor[4];
int pre[10][4] = { {0,0,0,0},
{0,0,0,0},
{1,0,0,0},
{0,1,0,0},
{2,0,0,0},
{0,0,1,0},
{1,1,0,0},
{0,0,0,1},
{3,0,0,0},
{0,2,0,0}
};

bool check()
{
    for (int j = 0; j<4; j++)
        if(factor[j]) return true;
    return false;
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _

	for (int i = 2; i<10; i++)
	    for (int j = 0; j<4; j++)
	        pre[i][j]+=pre[i-1][j];


	cin>>n>>s;
	for (int i = 0; i<n; i++)
    {
        if(s[i]=='0' || s[i] == '1') continue;
        m = s[i] - '0';

        for (int j = 0; j<4; j++)
            factor[j]+=pre[m][j];
    }
	string ans="";

	while(check())
    {

        m = 3;
        for (; m>=0; m--)
        {
            if(factor[m]) break;
        }
        char now = primes[m]+'0';
        t = factor[m];
        m = primes[m];
        for (int i = 0; i<t; i++)
            ans+=now;
        for (int i = 0; i<t; i++)
            for (int j = 0; j<4; j++)
                factor[j]-=pre[m][j];
    }

	cout<<ans;

   return 0;
}
