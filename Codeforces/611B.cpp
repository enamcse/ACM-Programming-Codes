/**
* H:\Dropbox\Code\Codeforces\611B.cpp
* Created on: 2015-12-30-21.20.01, Wednesday
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

#ifdef ENAM
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...)
#endif

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

ll a, b, ans=0;

ll getnext(ll x)
{
    int last=0, zero=0;
    for (int i = 62; i>=0; i--)
    {
        if(x&(1LL<<i)) {last = i;break;}
    }


    for (int i = 0; i<last; i++)
    {
        if(!(x&(1LL<<i))) {zero=i;break;}
    }
    if(zero==0){
        x = (1LL<<(last+2))-1;
        x^=(1LL<<(last));
//        cout<<"x:"<<x<<endl;
        return x;
    }
    x^=(1LL<<zero);
    x^=(1LL<<(zero-1));
    return x;
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m=-1, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>a>>b;
    t=0;
    for (int i = 62; i>=0; i--)
    {
        if(a&(1LL<<i))
        {
//            cout<<i<<";"<<endl;
            if(m==-1) m=i;
        }
        else if(m!=-1) t++;
    }
//    cout<<t<<endl;
    if(t==0)
    {
        a = (1LL<<(m+2))-1;
        a^=(1LL<<m);
    }
    else
    {
        for (int i = 0; i<=62&&t>1; i++)
            if(!(a&(1LL<<i))) a^=(1LL<<i), t--;
    }
    if(a<=b) ans=1;
//    cout<<a<<endl;
//    return 0;

    a=getnext(a);
    while(a<=b)
    {
//        cout<<a<<endl;
//        getchar();
        ans++;
        a=getnext(a);
    }

    cout<<ans;

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
