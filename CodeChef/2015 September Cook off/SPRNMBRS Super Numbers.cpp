/**
* H:\Dropbox\Code\CodeChef\2015 September Cook off\SPRNMBRS Super Numbers.cpp
* Created on: 2015-09-20-23.27.40, Sunday
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

vector<ll>v;

ll pow3[45];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    ll up = (1e18);
    up+=1000;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    ll l, r, now;
    pow3[1] = 3;
    for (int i = 2; i<40; i++)
    {
        pow3[i]=pow3[i-1]*3LL;
    }

    v.pb(1);

    for (int i = 1; i<62; i++)
    {
        v.pb((1LL<<i));
        for (int j = 1; j<45; j++)
        {
            now = (1LL<<i)*pow3[j];
            if(now>up) break;
            v.pb(now);
        }
    }
    sort(all(v));

//    for (int i = 0; i<20; i++) cerr<<v[i]<<endl;
//    cout<<v.size()<<endl;

    cin>>t;

    while(t--)
    {
        cin>>l>>r;

        cout<<(upper_bound(all(v),r)-lower_bound(all(v),l))<<"\n";
    }



//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}