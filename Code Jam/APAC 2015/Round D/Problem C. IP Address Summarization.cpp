/**
* H:\Dropbox\Code\Code Jam\APAC 2015\Round D\Problem C. IP Address Summarization.cpp
* Created on: 2015-11-08-11.45.50, Sunday
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

struct node{
    int zero,one,p,d,last;
};

ll aa[33];
ll bb[33];
ll cc[33];
ll dd[33];

//map< pair<ll,ll>, pair<ll,ll> >mpp;

//bool comp(const input &a, const input &b)
//{
//    return a.p<b.p;
//}
int cnt;
node arr[600000];

int getnew(ll k)
{
    arr[cnt].one = -1;
    arr[cnt].zero = -1;
    arr[cnt].last = 0;
    arr[cnt].d = k;
    return cnt++;
}

void goo(ll x, ll p, ll n, ll d)
{
    if(d==p)
    {
        arr[n].last = 1;
        return;
    }
    if(x&(1LL<<arr[n].d))
    {
        if(arr[n].one==-1)
        {
            arr[n].one = getnew(d+1);
        }
        goo(x,p,arr[n].one,d+1);
    }
    else
    {
        if(arr[n].zero==-1)
        {
            arr[n].zero = getnew(d+1);
        }
        goo(x,p,arr[n].zero,d+1);
    }
}

int wa,wb,wc,wd,wp;

void printnow()
{

}

int tra(ll n, ll d)
{
    if(arr[n].last) {wp=d;printnow();return -1;}
    int a = arr[n].zero, b = arr[n].one;
    if(a==-1&&b==-1) {wp=d;printnow();return ;}
    if(a!=-1)
    {

    }
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    ll t, n, m, cas=1;
    ll a, b, c, d, p, tot;
//    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    set<string>ans;
    string s;
    aa[0] = 0;
    bb[0] = 0;
    cc[0] = 0;
    dd[0] = 0;
    for (int i = 1; i<=32; i++)
    {
        aa[i] = aa[i-1];
        bb[i] = bb[i-1];
        cc[i] = cc[i-1];
        dd[i] = dd[i-1];
        if(i<=8) aa[i]|=(1LL<<(8-i));
        else if(i<=16) bb[i]|=(1LL<<(16-i));
        else if(i<=24) cc[i]|=(1LL<<(24-i));
        else if(i<=32) dd[i]|=(1LL<<(32-i));
//        cout<<(1LL<<(i-16))<<":::::"<<(i-16)<<endl;
        p = i;
//        cerr<<i <<" = "<<aa[p]<<" "<<bb[p]<<" "<<cc[p]<<" "<<dd[p]<<" "<<p<<endl;
    }

    scanf("%lld", &t);

    while(t--)
    {
        cnt=0;
        arr[cnt].p = 0;
        arr[cnt].zero = -1;
        arr[cnt++].one = -1;

        ans.clear();
        scanf("%d", &n);
        for (int i = 0; i<n; i++)
        {
            scanf("%lld.%lld.%lld.%lld/%lld", &a,&b,&c,&d,&p);
            a = (aa[p]&a);
            b = (bb[p]&b);
            c = (cc[p]&c);
            d = (dd[p]&d);
            tot = (a<<24)|(b<<16)|(c<<8)|d;
            goo(tot,p,0,0);
//            cerr<<i <<" = "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<tot<<"\n";
//            cerr<<i <<" = "<<aa[p]<<" "<<bb[p]<<" "<<cc[p]<<" "<<dd[p]<<" "<<p<<"\n";
//            v.pb(input(a,b,c,d,p));
        }


    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}