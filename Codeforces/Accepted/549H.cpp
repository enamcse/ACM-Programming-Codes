/**
* H:\Dropbox\Code\Codeforces\549H.cpp
* Created on: 2015-06-06-19.37.40, Saturday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 200005
#define pb(a) push_back(a)
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

long double a, b,c ,d ;

bool getit(long double now)
{
//    cerr<<now<<endl;
    long double mn1, mx1, ting, mx2, mn2;

    mx1 = mn1 = (a-now)*(d-now);
    ting = (a-now)*(d+now);
    mn1 = min(mn1, ting);
    mx1 = max(mx1, ting);
    ting = (a+now)*(d-now);
    mn1 = min(mn1, ting);
    mx1 = max(mx1, ting);
    ting = (a+now)*(d+now);
    mn1 = min(mn1, ting);
    mx1 = max(mx1, ting);


    mx2 = mn2 = ((b-now)*(c-now));
    ting = (b-now)*(c+now);
    mn2 = min(mn2, ting);
    mx2 = max(mx2, ting);
    ting = (b+now)*(c-now);
    mn2 = min(mn2, ting);
    mx2 = max(mx2, ting);
    ting = (b+now)*(c+now);
    mn2 = min(mn2, ting);
    mx2 = max(mx2, ting);

    if(mx1>=mn2 && mx1 <= mx2) return true;
    if(mx2>=mn1 && mx2 <= mx1) return true;

    if(mn1<=mx2 && mn1 >= mn2) return true;
    if(mn2<=mx1 && mn2 >= mn1) return true;
    return false;
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>a>>b>>c>>d;

    long double low=0, high=1e9;
    long double ans ,  mid;
    for (int i = 0; i<100; i++)
    {
        mid = (low+high)/2.0;

        if(getit(mid))
        {
//            cout<<":"<<mid<<":"<<endl;
            ans = mid;
            high = mid;
        }
        else low = mid;
    }
//cout<<":"<<mid<<":"<<endl;
    cout<<fixed<<setprecision(10)<<ans;


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
