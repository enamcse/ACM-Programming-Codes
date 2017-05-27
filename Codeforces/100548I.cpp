/**
* H:\Dropbox\Code\Codeforces\100548I.cpp
* Created on: 2015-11-09-04.04.41, Monday
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

struct ad{
    string s;
    ll n;
    ad(){}
    ad(string s_, ll n_)
    {
        s = s_;
        n = n_;
    }

    bool operator < (const ad &p) const
    {
        return n==p.n? s > p.s : n > p.n;
    }
};

ll aa[33];
ll bb[33];
ll cc[33];
ll dd[33];

char line[100], line1[100];

vector<ad>data;

void insdata(ll x,ll p)
{

    for (int i = 31; i>=0; i++)
    {
        if(x&(1LL<<i)) line[31-i] = '1';
        else line[31-i] = '0';
    }
    line[32]=0;
    data.pb(ad(line,p));
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,p,a,b,c,d,tot;
    set<string>ans, done;
//    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    string s;
    ad now;
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

    scanf("%d", &t);

    while(t--)
    {
        data.clear();
        ans.clear();
        done.clear();
        scanf("%d", &n);
        for (int i = 0; i<n; i++)
        {
            scanf("%lld.%lld.%lld.%lld/%lld", &a,&b,&c,&d,&p);
            a = (aa[p]&a);
            b = (bb[p]&b);
            c = (cc[p]&c);
            d = (dd[p]&d);
            tot = (a<<24)|(b<<16)|(c<<8)|d;
            insdata(tot,p);
//            cerr<<i <<" = "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<tot<<"\n";
//            cerr<<i <<" = "<<aa[p]<<" "<<bb[p]<<" "<<cc[p]<<" "<<dd[p]<<" "<<p<<"\n";
        }

    while(!data.empty())
    {
        now = data.top();
        data.pop();
        if(data.empty())
        {
            if(now.n==0) break;
            sprintf(line,"%s/%lld", now.s.c_str(), now.n);
            done.insert(line);
            now.s[ now.n-1 ] = ((now.s[now.n-1]-'0')^1)+'0';

            for (int i = now.n-1; i>=1; i--)
                ;

            sprintf(line,"%s/%lld", now.s.c_str(), now.n);
            ans.insert(line);
        }

    }


    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
