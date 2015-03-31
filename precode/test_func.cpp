/**
* H:\Dropbox\Code\precode\test_func.cpp
* Created on: 2015-01-13-11.14.33, Tuesday
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
#define cntbit(mask) __builtin_popcount(mask)   ///returns # of ones in binary representation, only for positive values, add ll for long long
#define lsbpos(mask) __builtin_ffs(mask)        ///returns the least significant bit position in binary representation(1-based, but returns 0 for x = 0), add ll for long long
#define lead0(mask) __builtin_clz(mask)         ///returns # of leading zeros in binary representation, only for positive values, add ll for long long
#define trail0(mask) __builtin_ctz(mask)        ///returns # of trailing zeros in binary representation, only for positive values, add ll for long long
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define itis(x) cerr << #x << " is " << x << endl;
#define itis(x,y) cerr << #x << " for "<< y << " is " << x << endl;
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n=20, m, cas=1;
    _
    ll a;

    for (int i = -3; i<n; i++)
        itis(trail0(i),i)


   return 0;
}
