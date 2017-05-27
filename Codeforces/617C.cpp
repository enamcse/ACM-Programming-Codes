/**
* E:\Dropbox\Code\Codeforces\617C.cpp
* Created on: 2016-01-23-22.06.52, Saturday
* Verdict: Solved
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

pair<ll,ll>a,b,x;



int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	ll n,ans;
	ans=inf;

    cin>>n;
    vector<pair<ll,ll>>v(n),dist(n);
    cin>>a.first>>a.second;
    cin>>b.first>>b.second;
    for(ll i = 0; i<n;i++)
        cin>>v[i].first>>v[i].second;
    for (ll i = 0; i<n; i++)
    {
        dist[i].first = (a.first-v[i].first)*(a.first-v[i].first)+(a.second-v[i].second)*(a.second-v[i].second);
        dist[i].second = (b.first-v[i].first)*(b.first-v[i].first)+(b.second-v[i].second)*(b.second-v[i].second);
    }
    sort(dist.rbegin(),dist.rend());


    for(int j = 0; j<n; j++)
    {
        x = {0,0};
        x.first = dist[j].first;
        for (ll i = 0; i<n; i++)
        {
            if(x.first>=dist[i].first) continue;

            x.second = max(x.second,dist[i].second);
        }
        ans = min(ans,x.first+x.second);
    }


    for(int j = 0; j<n; j++)
    {
        x = {0,0};
        x.second = dist[j].second;
        for (ll i = 0; i<n; i++)
        {
            if(x.second>=dist[i].second) continue;

            x.first = max(x.first,dist[i].first);
        }
        ans = min(ans,x.first+x.second);
    }


    cout<<ans;
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
