/**
* H:\Dropbox\Code\Code Jam\APAC 2015\Round C\Problem B. gFiles.cpp
* Created on: 2015-10-18-11.57.56, Sunday
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
#define fread freopen("B-large-practice.in","r",stdin)
//#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("outputBLargePractice.txt","w",stdout)
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

vector< pair<ll,ll> >v;
int n;

int check(ll x)
{
    ll num;
    ll now;
    for (int i = 0; i<n; i++)
    {
        num = v[i].second*100.0;
        now = (num/x);
//        if(x == 937)cout<<i<<" - "<<v[i].first<<" : "<<v[i].second<<" = "<<(num/(double)x)<<endl;
//        if(abs(now-num)<0.005) continue;
        if(now < v[i].first) return 2;
        else if(now > v[i].first) return 1;
    }

    return 0;
}

int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    ll t, m, cas=1,x,y;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>t;

    while(t--)
    {
        cin>>n;
        v.clear();
        for (int i = 0; i<n; i++)
        {
            cin>>x>>y;
            v.pb({x,y});
        }
        cout<<"Case #"<<cas++<<": ";
        if(v[n-1].first == 100)
        {
            cout<<v[n-1].second<<"\n";
            continue;
        }
        ll l = v[n-1].second, r = 1e15, mid, ans = -1;

        for (int i = 0; i<500; i++)
        {
            if(r<l) break;
            mid = (l+r)/2;
            m = check(mid);
            if(m==0)
            {
                ans = mid;
                break;
            }
            else if(m==1)
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
//        cerr<<"?? = "<<check(937)<<endl;
//        cout<<ans<<"???"<<endl;
        if(r<l || (check(ans+1)==0||check(ans-1)==0)) cout<<"-1\n";
        else cout<<ans<<"\n";

    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}