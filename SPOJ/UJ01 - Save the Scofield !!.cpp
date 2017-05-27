/**
* E:\Dropbox\Code\SPOJ\UJ01 - Save the Scofield !!.cpp
* Created on: 2016-04-23-19.11.20, Saturday
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

#ifdef ENAM
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...)
#endif

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

ll lcm(ll a, ll b)
{
    return a*b/__gcd(a,b);
}

ll check(ll a, ll b, ll c)
{
    return (c/a+c/b-c/lcm(a,b));
}

int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	ll a,b, cas = 1,t,n,m,x,y,z,mid;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>t;

    while(t--)
    {
        cin>>a>>b>>n;
        x = 0, y = 1e18;
        m = -1;
        while(x<=y)
        {
            mid = (x+y)/2;
            z = check(a,b,mid);
//            cout<<"a = "<<a<<" b = "<<b<<" n = "<<n<<" z = "<<z<<" mid = "<<mid<<endl;
            if(z==n){m=mid;break;}
            else if(z<n)
            {
                x=mid+1;
            }
            else y = mid-1;
        }
        assert(m!=-1);
//        while(check(a,b,m-1)==n&&m) m--;
        cout<<max((m/a)*a,(m/b)*b)<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
