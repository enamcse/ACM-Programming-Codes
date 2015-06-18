/**
* H:\Dropbox\Code\HackerRank\HackerRank HiringSprint\Gifts1.cpp
* Created on: 2015-06-14-18.38.10, Sunday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
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
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;
vector<int>B,G,S, mult;

int n;

map< tuple<int,int,int,int,int,int,int>, int>dp;

int rec(int pos, int b1, int b2, int s1, int s2, int g1, int g2)
{
    if(pos==n) return 0;

    if(dp.count(make_tuple(b1,b2,s1,s2,g1,g2,pos)) != 0) return dp[ make_tuple(b1,b2,s1,s2,g1,g2,pos)  ];
    int &ret = dp[ make_tuple(b1,b2,s1,s2,g1,g2,pos) ];

    ret = 0;
    if(b1<=b2)
    {
        ret = max(ret, rec(pos+1, b1+1,b2,s1,s2,g1,g2)+B[b1]*mult[pos]);
        ret = max(ret, rec(pos+1, b1,b2-1,s1,s2,g1,g2)+B[b2]*mult[pos]);
    }
    if(s1<=s2)
    {
        ret = max(ret, rec(pos+1, b1,b2,s1+1,s2,g1,g2)+S[s1]*mult[pos]);
        ret = max(ret, rec(pos+1, b1,b2,s1,s2-1,g1,g2)+S[s2]*mult[pos]);
    }
    if(g1<=g2)
    {
        ret = max(ret, rec(pos+1, b1,b2,s1,s2,g1+1,g2)+G[g1]*mult[pos]);
        ret = max(ret, rec(pos+1, b1,b2,s1,s2,g1,g2-1)+G[g2]*mult[pos]);
    }
    return ret;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, m, cas=1,b,g,s;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>b>>s>>g;
    n = b+g+s;
    for (int i = 0; i<n; i++)
    {
        cin>>m;
        if(i<b) B.pb(m);
        else if(i<b+s) S.pb(m);
        else G.pb(m);
    }

    for (int i = 0; i<n; i++)
    {
        cin>>m;
        mult.pb(m);
    }

    int sum = rec(0,0,B.size()-1,0,S.size()-1,0,G.size()-1);

    cout<<sum;
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
