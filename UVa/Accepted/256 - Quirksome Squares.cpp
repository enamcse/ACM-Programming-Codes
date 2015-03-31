/**
* H:\Dropbox\Code\UVa\256 - Quirksome Squares.cpp
* Created on: 2015-02-09-22.11.45, Monday
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

vector<int>v[4];

void gen(int p)
{
    int k =0;
    int n = pow(10,p+1);
	for (ll i = 0; i<n; i++)
	    for (ll j = 0; j<n; j++,k++)
	        if((i+j)*(i+j) == k) v[p].pb(k);
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int n;
    for (int i = 0; i<4; i++)
	gen(i);
    char format[20];
    while(~scanf("%d", &n))
    {
        sprintf(format,"%%0%dd\n",n);
        n>>=1;
        n--;


        for (int i = 0; i<v[n].size(); i++)
            printf(format,v[n][i]);
    }


   return 0;
}
