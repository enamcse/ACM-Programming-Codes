/**
* E:\Dropbox\Code\Codeforces\672D.cpp
* Created on: 2016-05-11-23.46.00, Wednesday
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

map<int,int>mpp;
vector< pair<int,int> >v;
ll tot;

int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	int cas = 1,t,n,m,p,mid,x,y,z,ans,k;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n>>k;

    if(n==1)
    {
        cout<<0;
        return 0;
    }

    for (int i=0; i<n; i++)
    {
        cin>>x;
        tot+=x;
        if(mpp.count(x)) mpp[x]++;
        else mpp[x]=1;
    }

    for(auto &w:mpp) v.pb({w.first,w.second});
    int st = v.size()-1, en = 0;
    ans = v[st].first-v[en].first;
//    cout<<ans<<endl;
    while(k&&en<st)
    {
        z=0;
        m = 0;
        p = v[st].first-v[st-1].first;
        mid = (m+p)/2;

        while(m<=p)
        {
            if(v[st].second*mid<=k)
            {
                z=mid;
                m=mid+1;
            }
            else p=mid-1;
        }


        if(z)
        {
            k-=(v[st].second*z);
            x=(z*v[st].second);
            v[st].first-=z;
            if(v[st].first==v[st-1].first)
            {
                v[st-1].second+=v[st].second;
                st--;
            }
        }
        else
        {
            v[st].second-=k;
            x = k;
            k = 0;
        }

        while(x&&en<st)
        {
            z=0;
            m = 0;
            p = v[en].first-v[en+1].first;
            mid = (m+p)/2;

            while(m<=p)
            {
                if(v[en].second*mid<=x)
                {
                    z=mid;
                    m=mid+1;
                }
                else p=mid-1;
            }
            if(z)
            {
                x-=(z*v[en].second);
                v[en].first-=z;
                if(v[en].first==v[en+1].first)
                {
                    v[en+1].second+=v[en].second;
                    en++;
                }
            }
            else
            {
                v[en].second-=x;
                x=0;
            }
        }
        ans = min(ans, v[st].first-v[en].first);
    }
    if(en>=st)
    {
//        cout<<"jere";
        if(tot%n==0) cout<<0;
        else cout<<1;
    }
    else cout<<ans;
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
