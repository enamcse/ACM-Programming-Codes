/**
* H:\Dropbox\Code\Codeforces\606A.cpp
* Created on: 2015-12-09-22.05.02, Wednesday
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

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    int a,aa, b,bb,c,cc;
    int p,q,r;
    cin>>a>>b>>c;
    cin>>aa>>bb>>cc;
    p = min(a,aa);
    q = min(b,bb);
    r = min(c,cc);
    a-=p;
    aa-=p;
    b-=q;
    bb-=q;
    c-=r;
    cc-=r;
//    cout<<aa<<" "<<bb<<" "<<cc<<" ";
//    cout<<a<<" "<<b<<" "<<c<<" ";
//    cout<<p<<" "<<q<<" "<<r<<endl;
    if(aa)
    {
        p=b/2;
        if(p>=aa)
        {
            b-=aa*2;
            aa=0;

        }
        else
        {
            aa-=p;
            b-=p*2;
        }
        p=c/2;
        if(p>=aa)
        {
            c-=aa*2;
            aa=0;

        }
        else
        {
            aa-=p;
            c-=p*2;
        }
    }
    if(bb)
    {
        p=a/2;
        if(p>=bb)
        {
            a-=bb*2;
            bb=0;

        }
        else
        {
            bb-=p;
            a-=p*2;
        }
        p=c/2;
        if(p>=bb)
        {
            c-=bb*2;
            bb=0;

        }
        else
        {
            bb-=p;
            c-=p*2;
        }
    }
    if(cc)
    {
        p=a/2;
        if(p>=cc)
        {
            a-=cc*2;
            cc=0;
        }
        else
        {
            cc-=p;
            a-=p*2;
        }
        p=b/2;
        if(p>=cc)
        {
            a-=cc*2;
            cc=0;
        }
        else
        {
            cc-=p;
            b-=p*2;
        }
    }

    cout<<( (aa+bb+cc==0)?"Yes":"No" );

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
