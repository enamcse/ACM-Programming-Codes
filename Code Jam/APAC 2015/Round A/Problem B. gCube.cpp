/**
* H:\Dropbox\Code\Code Jam\APAC 2015\Problem B. gCube.cpp
* Created on: 2015-08-23-12.18.33, Sunday
* Verdict: Not Solved
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
#define fread freopen("B-large.in","r",stdin)
#define fwrite freopen("outputBlarge.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case #"<<cas++<<":\n";
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

ll a[1005];

long double get(int x, int y)
{
    long double ret = 1.0;
    for (int i = x; i<=y; i++)
        ret*=pow(a[i],(long double)1.0/(y-x+1.0));
    return ret;
}

int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    ll t, n, m, cas=1,x,y;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>t;

    while(t--)
    {
        cin>>n>>m;
        for (int i = 0; i<n; i++)
        {
            cin>>a[i];
        }
        csco
        for (int i = 0; i<m; i++)
        {
            cin>>x>>y;
            cout<<setprecision(10)<<fixed<<get(x,y)<<"\n";
        }
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
