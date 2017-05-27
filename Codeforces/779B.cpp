/**
* E:\Dropbox\Code\Codeforces\779B.cpp
* Created on: 2017-03-19-09.48.40, Sunday
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
#define rall(a) a.rbegin(),a.rend()
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
#define csco cout<<"Case "<<cas++<<": ";
#define mod 1000000007

#ifdef ENAM
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...)
#endif

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;
int a[sz],b[sz];

bool comp(const pair<int, pair<int, int > > &a, const pair<int, pair<int, int > > &b)
{
    return ((a.second.first<a.second.second &&
            b.second.first<b.second.second)?
            a.first>=b.first:a.first<b.first);
}

int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	int cas = 1,t,n,m,x,y,z,k;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n>>k;
    vector< pair<int, pair<int, int > > >p(n);
    for (int i = 0; i<n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i<n; i++)
    {
        cin>>b[i];
    }
    for (int i = 0; i<n; i++)
    {
        p[i].first=abs(b[i]-a[i]);
        p[i].second.first=a[i];
        p[i].second.second=b[i];
    }
    sort(all(p),comp);
    ll ans=0;
    for (int i = 0; i<k; i++)
        ans+=p[i].second.first;
    for (int i = k; i<n; i++)
        ans+=min(p[i].second.second,p[i].second.first);
        cout<<ans<<endl;
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
