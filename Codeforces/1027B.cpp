/**
* E:\Dropbox\Code\Codeforces\1027B.cpp
* Created on: 2018-08-18-20.53.49, Saturday
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
using namespace std;

struct _deb{
    template<typename T> _deb& operator , (const T& _temp){
        cerr<<_temp<<" ";
        return *this;
    }
}dbg;

/// debug template credit: Bidhan Roy

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}


int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	ll q,cas = 1,t,n,m,x,y,z;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

	cin>>n>>q;
    while(q--)
    {
        cin>>x>>y;
        m = x+y;
        z = 0;
        if(m&1LL)
        {
            z = (n*n)/2 + (n&1LL);
            z += n*((x-1)/2);
            z+= ((x&1LL)?0:(n/2));
            z++;
            z+=(y-1)/2;
        }
        else
        {
            z = n*((x-1)/2);
            z+= ((x&1LL)?0:((n/2)+(n&1LL)));
            z++;
            z+=(y-1)/2;
        }
        cout << z <<"\n";
    }
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}