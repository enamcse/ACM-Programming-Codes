/**
* E:\Dropbox\Code\Codeforces\1339C.cpp
* Created on: 2020-04-13-03.16.46, Monday
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
#define csco cout<<"Case "<<cas++<<": ";
#define mod 1000000007

using namespace std;


ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

ll arr[sz];

int inc_pow2(ll x)
{
//    cout << "here:" << x << endl;
    if(x<=0) return 0;
    int ret = 0;
    for (int i = 0; i<50; i++)
    {
        if(x&(1LL<<i)){
            ret = i;
        }
    }
    return ret+1;
}

int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	ll cas = 1,t,n;
	int ans=0, k;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin >> t;

    for (int m = 0; m<t; m++)
    {
        ans = 0;
        cin >> n;
        for (int i = 0; i<n; i++)
            cin >> arr[i];
        for (int i = 1; i<n; i++)
        {
            k = inc_pow2(arr[i-1]-arr[i]);
            if(k) arr[i] += (arr[i-1]-arr[i]);
//            cout << arr[i] << endl;
//            cout << ans << ":here:" << k << endl;
            ans = max(ans,k);
        }
        cout << ans << "\n";
    }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
/**
3
4
1 7 6 5
5
1 2 3 4 5
2
0 -4

1
6
-7 1 5 9 -6 -9


*/
