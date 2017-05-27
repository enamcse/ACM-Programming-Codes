/**
* E:\Dropbox\Code\Codemarshal\CodeMask Championship-2016 Qualification Round-03 (Last Round Before Onsite Contest)\D.cpp
* Created on: 2016-03-31-18.57.50, Thursday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((ll)a.size())
#define sz 1000005
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

ll fact[sz];

int get(int n)
{
    ll ret = fact[n];
    ret*=inverse_mod(fact[n-3],mod);
    ret%=mod;
    ret*=inverse_mod(fact[3],mod);
    ret%=mod;
    return ret;
}

int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	int cas = 1,t,n,m,x,y,z;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    fact[0] = 1;
    for (int i = 1; i<sz; i++)
    {
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
    }

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &n, &m);
        if(m<3&&n<3)
        {
            printf("0\n");
            continue;
        }
        if(n<3) n = 3;


        printf("%d\n", (get(m)-get(n-1)+mod)%mod);

    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
