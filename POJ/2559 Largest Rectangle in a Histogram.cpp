/**
* H:\Dropbox\Code\POJ\2559 Largest Rectangle in a Histogram.cpp
* Created on: 2015-05-29-01.08.55, Friday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include<stdio.h>
#include<iostream>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 100005
#define pb(a) push_back(a)
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

ll  val[sz],le[sz], ri[sz];


void histogram(int n)
{
    for (int i = 1; i<=n; i++)
        le[i] = ri[i] = i;

    for (int i = 1; i<=n; i++)
    {
        while(le[i]>1 && val[ i ]<= val[le[i]-1])
            le[i]=le[le[i]-1];
    }

    for (int i = n; i>=1; i--)
    {
        while(ri[i]<n && val[ i ]<= val[ri[i]+1])
            ri[i]=ri[ri[i]+1];
    }
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    ll t, n, m, cas=1, ans, l, r, ind, mid,f,s;

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

//    scanf("%lld", &t);

    while(~scanf("%lld", &n)&&n)
    {
        ans = 0;
        ;

        for (int i = 1; i<=n; i++)
            scanf("%lld", &val[i]);

        val[n+1]=-1;

        histogram(n);

        for (int i = 1; i<=n; i++)
            ans = max(ans,(ri[i]-le[i]+1)*val[i]);

//        cp
        printf("%lld\n", ans);
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}