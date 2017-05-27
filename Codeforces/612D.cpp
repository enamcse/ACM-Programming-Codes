/**
* H:\Dropbox\Code\Codeforces\612D.cpp
* Created on: 2015-12-25-22.33.04, Friday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 1000005
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (2e9)
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

ll a[sz],b[sz];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    ll t, n, m, cas=1,k;
    vector<pair<ll,ll>>v,ans;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n>>k;

    for (int i = 0; i<n; i++)
    {
        cin>>a[i]>>b[i];
    }

    sort(a,a+n);
    sort(b,b+n);

    m=0;
    int x,y;
    x = y = 0;
    t=-inf;
//    b[n]=inf;
    while(y<n)
    {
        if(x<n&&a[x]<b[y])
        {
            m++;

            if(m==k)
            {
                if(t==-inf) t = a[x];
            }

            x++;
        }
        else if(x<n&&a[x]==b[y])
        {
            if(m+1==k) v.pb({a[x],b[y]});
            x++;
            y++;
            //somework to be done
        }
        else
        {
            if(m==k)
            {
                v.pb({t,b[y]});
                t=-inf;
            }
            m--;
            y++;
        }
    }

    n = v.size();

    if(n==0)
    {
        cout<<0;
        return 0;
    }

    t=-inf;
    for (int i = 0; i<n; i++)
    {
        if(t==-inf) t= v[i].first;
        else if(v[i].first==v[i-1].second) continue;
        else
        {
            ans.pb({t,v[i-1].second});
            t = v[i].first;
        }
    }
    ans.pb({t,v[n-1].second});
    n = ans.size();
    cout<<n<<"\n";
    for (int i = 0; i<n; i++)
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
