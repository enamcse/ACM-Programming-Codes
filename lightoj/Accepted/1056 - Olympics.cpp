/**
* H:\Dropbox\Code\lightoj\1056 - Olympics.cpp
* Created on: 2015-02-04-04.31.29, Wednesday
* Verdict: Solved
* Comment: This problem gives Runtime Error while submitting with cin/cout with sync
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

double a, b;

inline bool check()
{
    double res, r;
    r = sqrt(a*a+b*b)/2.0;
//    if(r<1e-12) return 0;
    res = acos(1.0-(b*b/(2*r*r)));
    res*=r;
    res+=a;
    res+=res;
    return res>400.0;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
//    _
    double lef, righ, mid;
//    char ch;
//    cin>>t;
    scanf("%d", &t);

    while(t--)
    {
//        cin>>n>>ch>>m;
        scanf("%d : %d", &n,&m);

        lef = 0.0; righ=100.0;

        for (int i=0; i<37; i++)
        {
            mid = (lef+righ)/2.0;

            a = n * mid;
            b = m * mid;
            if(check()) righ =mid;
            else lef=mid;
        }
        printf("Case %d: %.9lf %.9lf\n", cas++, a, b);
//        cout<<"Case "<<cas++<<": "<<setprecision(9)<<fixed<<a<<" "<<b<<"\n";
    }



   return 0;
}
