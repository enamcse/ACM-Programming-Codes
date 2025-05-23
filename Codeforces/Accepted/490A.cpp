/**
* H:\Dropbox\Code\Codeforces\490A.cpp
*
* Created on: 2014-11-23-14.59.59, Sunday
* Author: Enamul Hassan
* Verdict: SOLVED
**/

//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include <set>
#include <string>
#include <stack>
#include <bitset>

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

vector<int>v[3];



int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1, ans=inf, a, b,c;
    cin>>n;

    a= b=c=0;

    for (int i = 0; i<n; i++)
    {
        cin>>m;
        if(m==1) a++,v[0].pb(i+1);
        else if(m==2) b++,v[1].pb(i+1);
        else if(m==3) c++,v[2].pb(i+1);;
    }

    ans = min(ans, a);
    ans = min(ans, b);
    ans = min(ans, c);

    cout<<ans<<"\n";

    for (int i = 0; i<ans; i++)
    {
        cout<<v[0][i]<<" "<<v[1][i]<<" "<<v[2][i]<<"\n";
    }

    return 0;
}
