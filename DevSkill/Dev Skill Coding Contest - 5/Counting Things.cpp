/**
* H:\Dropbox\Code\DevSkill\Dev Skill Coding Contest - 5\Counting Things.cpp
* Created on: 2015-08-15-21.30.16, Saturday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 200005
#define pb push_back
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
ll a, k, n, l, r, mid, ans;
    int t, d;
bool check(ll now)
{
    ll nows = now-1, pp = now;
    if(nows&1) now>>=1LL;
    else nows>>=1LL;
    double mm = (pp*1.0)*(a*1.0)+(double)d*((1.0*now*(nows*1.0)));
    if(mm>1e18) return false;
    ll ting = pp*a+(ll)d*(now*nows);
//    cout<<now<<"H"<<ting<<"K="<<k<<endl;
    return ting<=k;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
//    freopen("strin.txt", "r", stdin);
//    freopen("strout.txt", "w", stdout);
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    scanf("%d", &t);

    while(t--)
    {
        scanf("%lld %d %lld", &a, &d, &k);
        if(d==0){
            printf("%d\n", a<=k);
            continue;
        }
        ans = 0;
        l = 0, r = 1e15;
        while(l<=r)
        {
//            cout<<l<<" | "<<r;
            mid = (l+r)/2;
//            cout<<" mid = "<<mid<<endl;
            if(check(mid)){
//                    cout<<ans<<"=ans"<<endl;
                ans = mid;
                l=mid+1;
            }
            else r = mid-1;
//            cout<<l<<" & "<<r<<endl;
        }
        printf("%lld\n", ans);
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
