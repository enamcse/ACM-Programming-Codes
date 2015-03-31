/**
* H:\Dropbox\Code\CodeChef\2015 January Challange\CHEFSTON Chef and Stones.cpp
* Created on: 2015-01-02-19.02.26, Friday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
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

//struct node{
//    int a, b;
//    node(){}
//    node(int a, int b) : a(a), b(b) {}
//};
//
//node data[sz];

int a[sz];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, k,cas=1, x;
    _
    ll ans;
    vector< pair<int,int> >now,temp;
    vector<pair<ll,ll> > v;
	cin>>t;

	while(t--)
    {
        cin>>n>>k;
        ans = 0;
        for (int i = 0; i<n; i++)
            cin>>a[i];
        now.clear();
        for (int i = 0; i<n; i++)
        {
            cin>>x;
            now.pb(make_pair(a[i],x));
        }

        while(1)
        {
            v.clear();
            temp.clear();
            for (int i = 0; i<now.size(); i++)
                if(now[i].first<=k)
                {
                    ll tew = k/now[i].first;
//                    cout<<i<<":"<<tew<<endl;
                    v.pb(make_pair(tew*now[i].second,tew*now[i].first));
                    temp.pb(now[i]);
                }
//                cout<<temp.size()<<"KK"<<endl;
            now = temp;
            sort(allr(v));
            if(v.size())
            {
                k-=v[0].second;
                ans+=v[0].first;
                break;
            }
            else break;
        }
        cout<<ans<<endl;
    }


   return 0;
}
