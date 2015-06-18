/**
* H:\Dropbox\Code\Codeforces\548C.cpp
* Created on: 2015-05-26-22.31.33, Tuesday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 2000005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("548C.txt","w",stderr)
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

int a[sz], b[sz];

int f[sz],s[sz], i1,i2;

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    ll t, n1,n2, m, cas=1, h1,a1,x1,y1,h2,a2,x2,y2,d1=-1,d2=-1, p1, p2, con, yy;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

        t=0;
        n1=n2=-1;
        cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;

        while(n1==-1||n2==-1)
        {
            if(h1==a1 && h2 == a2)
            {
                cout<<t;
                return 0;
            }
            if(a[h1]&&n1==-1) n1 = t,i1=a[h1]-1;
            else f[t] = h1;

            if(d1==-1&&h1==a1) d1 = t;
            if(d2==-1&&h2==a2) d2 = t;

            if(b[h2]&&n2==-1) n2 = t,i2=b[h2]-1;
            else s[t] = h2;
            a[h1]=t+1;
            b[h2]=t+1;

            h1 = (x1*h1+y1)%m;
            h2 = (x2*h2+y2)%m;
            t++;
        }

        if(d1==-1 || d2==-1 || d1<i1 || d2<i2)
        {
            cout<<-1;
            return 0;
        }

        cerr<<"d1 = "<<d1<<", d2 = "<<d2<<endl;
        cerr<<"i1 = "<<i1<<", i2 = "<<i2<<endl;


        d1-=i1;
        d2-=i2;
        n1-=i1;
        n2-=i2;
        p1 = (t-i1)%n1;
        p2 = (t-i2)%n2;
        cerr<<"n1 = "<<n1<<", n2 = "<<n2<<endl;

        if((p1==d1 && p2 == d2))
            {
                cout<<t;
                return 0;
            }

        while(p1!=d1)
        {
            p1++;
            p2++;
            t++;
            p1 = (t-i1)%n1;
            p2 = (t-i2)%n2;
        }

        if(p1==d1 && p2 == d2)
            {
                cout<<t;
                return 0;
            }

        if(p2<=d2)  con = d2 - p2;
        else con = n2-p2+d2;

        for (ll i = 0; i<1e7; i++)
        {
            if((con+i*n2)%n1==0)
            {
                cout<<t+(con+i*n2);
                return 0;
            }
        }


        cout<<-1;

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}

/**
129081
128454 36771
116353 2940
95311 22200
579 118683
*/
