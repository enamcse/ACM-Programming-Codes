/**
* E:\Dropbox\Code\Codeforces\617D.cpp
* Created on: 2016-01-23-22.57.09, Saturday
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
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007

#ifdef ENAM
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...)
#endif

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

pair<int,int>x[3];

int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	int mn,mx;
	for (int i = 0; i<3; i++)
    {
        cin>>x[i].first>>x[i].second;
    }

    if(x[0].first==x[1].first&&x[2].first==x[1].first) {cout<<1<<endl;return 0;}
    if(x[0].second==x[1].second&&x[2].second==x[1].second) {cout<<1<<endl;return 0;}
    if(x[0].first==x[1].first)
    {
        mn = min(x[0].second,x[1].second);
        mx = max(x[0].second,x[1].second);
        if(x[2].second>=mx||x[2].second<=mn)
        {
            cout<<2<<endl;
            return 0;
        }
    }
    if(x[2].first==x[1].first)
    {
        mn = min(x[2].second,x[1].second);
        mx = max(x[2].second,x[1].second);
        if(x[0].second>=mx||x[0].second<=mn)
        {
            cout<<2<<endl;
            return 0;
        }
    }
    if(x[0].first==x[2].first)
    {
        mn = min(x[0].second,x[2].second);
        mx = max(x[0].second,x[2].second);
        if(x[1].second>=mx||x[1].second<=mn)
        {
            cout<<2<<endl;
            return 0;
        }
    }
    if(x[0].second==x[1].second)
    {
        mn = min(x[0].first,x[1].first);
        mx = max(x[0].first,x[1].first);
        if(x[2].first>=mx||x[2].first<=mn)
        {
            cout<<2<<endl;
            return 0;
        }
    }
    if(x[2].second==x[1].second)
    {
        mn = min(x[2].first,x[1].first);
        mx = max(x[2].first,x[1].first);
        if(x[0].first>=mx||x[0].first<=mn)
        {
            cout<<2<<endl;
            return 0;
        }
    }
    if(x[0].second==x[2].second)
    {
        mn = min(x[0].first,x[2].first);
        mx = max(x[0].first,x[2].first);
        if(x[1].first>=mx||x[1].first<=mn)
        {
            cout<<2<<endl;
            return 0;
        }
    }
    cout<<3<<endl;
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
