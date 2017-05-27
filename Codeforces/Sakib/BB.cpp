/**
* E:\Dropbox\Code\Codemarshal\CodeMask Championship-2016 Qualification Round-02\B.cpp
* Created on: 2016-02-25-19.22.57, Thursday
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

ll f (ll n) {
    ll a = 0;
    while (n >= 5) {
        a += n / 5LL;
        n /= 5LL;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);

    ll m;
    while (cin >> m) {
        ll st = 1E12, nd = -1;

        ll lo = 0, hi = 1E12;
        while (lo <= hi) {
            ll mid = (lo + hi) >> 1LL;
            if (f(mid) > m) hi = mid - 1LL;
            else if (f(mid) < m) lo = mid + 1LL;
            else {
                st = mid;
                hi = mid - 1LL;
            }
        }

        lo = 0, hi = 1E12;
        while (lo <= hi) {
            ll mid = (lo + hi) >> 1LL;
            if (f(mid) > m) hi = mid - 1LL;
            else if (f(mid) < m) lo = mid + 1LL;
            else {
                nd = mid;
                lo = mid + 1LL;
            }
        }

        if (st > nd) cout << 0 << endl;
        else {
            cout << nd - st + 1LL << endl;
            for (ll i = st; i <= nd; i++) {
                cout << i << ' ' ;
            }
            cout << endl;
        }
    }

   return 0;
}
