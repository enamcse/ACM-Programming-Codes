/**
* E:\Dropbox\Code\Code Jam\APAC 2016\Round A\Problem C. Jane's Flower Shop.cpp
* Created on: 2016-07-10-12.29.51, Sunday
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
#define LL long double
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("C-large.in","r",stdin)
#define fwrite freopen("C-large-out.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case #"<<cas++<<": ";
#define mod 1000000007

#ifdef ENAM
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...)
#endif

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

LL C[105];

long double what(LL x,int n)
{
    LL ret = 0.0,mul=1.0;
    int p=0;
    for(int i = n; i>0; i--)
    {
        ret+=mul*C[i];
        mul *=(x+1.0);
    }
    ret-=mul*C[0];
    return ret;
}

long double ts(int n)
{
    LL le = -1, ri = 1,lt,rt,aa,bb,pa,pb;
    pa = what(le,n);
    pb = what(ri,n);
    for(int i = 0; i<200; i++)
    {
        if(abs(le-ri)<1e-10) break;
//        lt = le + (ri-le)/3.0;
//        rt = ri - (ri-le)/3.0;
        aa = what(le + (ri-le)/3.0,n);
        bb = what(ri - (ri-le)/3.0,n);
//        cerr<<"le = "<< le<<" lt = "<<lt<<" ri = "<<ri <<" rt = "<<rt<< " aa = "<<aa <<" bb = "<<bb <<endl;
        if((pa<0&&aa<0) || (pa>0&&aa>0) )
        {
            le = le + (ri-le)/3.0;
            pa = aa;
        }
        else if((pb<0&&bb<0) || (pb>0&&bb>0))
         {
             ri = ri - (ri-le)/3.0;
             pb = bb;
         }
         else assert(0);
    }
    return (le+ri)/2.0;
}

int main()
{
#ifdef ENAM
      fread;
  fwrite;
#endif // ENAM
	_
	int cas = 1,t,n,m,x,y,z;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>t;

    while(t--)
    {
        cin>>n;
        for(int i = 0; i<=n; i++) cin>>C[i];
        csco
        cout<<setprecision(12)<<fixed<<ts(n)<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
