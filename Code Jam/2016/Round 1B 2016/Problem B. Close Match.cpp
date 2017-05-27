/**
* E:\Dropbox\Code\Code Jam\2016\Round 1B 2016\Problem B. Close Match.cpp
* Created on: 2016-04-30-22.40.23, Saturday
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
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("B-small-attempt1.in","r",stdin)
#define fwrite freopen("B-small-1.txt","w",stdout)
#define inf (2e18)
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

char aa[10],bb[10];string a,b,aaa,bbb;
bool ok;
ll n;
char wow[19][10] ={"","%01lld","%02lld","%03lld","%04lld","%05lld","%06lld","%07lld","%08lld","%09lld","%10lld","%11lld","%12lld","%13lld","%14lld","%15lld","%16lld","%17lld","%18lld"};
ll nexta(ll x)
{
    sprintf(aa,wow[n],x);
    x=0;
    for (ll i = a.size()-1; i>=0; i--)
        if(a[i]!='?')
        {
            if(aa[i]>a[i])x=1;
            aa[i]=a[i];
        }
        else if(x)
        {
            if(aa[i]!='9')aa[i]++,x=0;
            else aa[i]='0';
        }
    if(x) return inf;
    x = 0;

    for (ll i = 0,j=1; i<n; i++)
    {
        x+=(j*(aa[n-i-1]-'0'));
        j*=10;
    }

    return x;
}
ll nextb(ll x)
{
    sprintf(aa,wow[n],x);
    x=0;
    for (ll i = a.size()-1; i>=0; i--)
        if(b[i]!='?')
        {
            if(aa[i]>b[i])x=1;
            aa[i]=b[i];
        }
        else if(x)
        {
            if(aa[i]!='9')aa[i]++,x=0;
            else aa[i]='0';
        }
    if(x) return inf;
    x=0;
    for (ll i = 0,j=1; i<n; i++)
    {
        x+=(j*(aa[n-i-1]-'0'));
        j*=10;
    }
    return x;
}

int main()
{
#ifdef ENAM
      fread;
  fwrite;
#endif // ENAM
	_
	ll cas = 1,t,m,x,y,z,lim,temp;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>t;
    cin.ignore();
    while(t--)
    {
        cin>>a>>b;
        m = 0;
        lim = 1;
        n = a.size();
        for (ll i = 0; i<n; i++)
            lim*=10;
        for (ll i = 0; i<lim; i++)
        {
            temp=nexta(i);
//            cerr<<i<<" > "<<temp<<endl;
            if(temp>=lim) break;
            else i = temp;
            for (ll j = 0; j<lim; j++)
            {
                temp=nextb(j);
//                cerr<<j<<" < "<<temp<<endl;
                if(temp>=lim) break;
                else j = temp;
                ok = true;

                sprintf(aa,wow[n],i);
                sprintf(bb,wow[n],j);
                aaa = aa;
                bbb = bb;

                for (ll k = 0; k<n; k++)
                {
                    if(a[k]=='?') continue;
                    if(a[k]!=aaa[k])
                    {
                        ok = false;
                        break;
                    }
                }
                for (ll k = 0; k<n; k++)
                {
                    if(b[k]=='?') continue;
                    if(b[k]!=bbb[k])
                    {
                        ok = false;
                        break;
                    }
                }
                if(ok)
                {
                    if(m==0)
                    {
                        m = 1;
                        x = abs(i-j);
                        y = i;
                        z = j;
                    }
                    else
                    {
                        if(abs(i-j)<x)
                        {
                            x = abs(i-j);
                            y = i;
                            z = j;
                        }
                    }
                }
            }
        }

        csco
        sprintf(aa,wow[n],y);
        sprintf(bb,wow[n],z);
        aaa = aa;
        bbb = bb;

        cout<<aaa<<" "<<bbb<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
