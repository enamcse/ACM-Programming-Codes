/**
* E:\Dropbox\Code\Codemarshal\CodeMask Championship-2016 Qualification Round-02\E.cpp
* Created on: 2016-02-25-19.43.50, Thursday
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

string months[] = {"","Baishakh", "Jaishtha", "Ashar", "Sraban", "Bhadra", "Ashwin", "Kartik" ,"Agrahayan", "Poush", "Magh", "Falgun", "Chaitra"};

int mm[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int xx[]={0,31,31,31,31,31,30,30,30,30,30,30/**/,30};
int get(int x, int y, int z)
{
    int ret = mm[y-1]+x;
    if(y-1>=2&&z) ret++;
//    cout<<"ret="<<ret<<endl;
    return ret;
}

int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	int cas = 1,t,n,m,x,y,z,p,q,r;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    for(int i = 1; i<=12; i++) mm[i]+=mm[i-1];

    bool lep;
    cin>>t;

    while(t--)
    {
        cin>>x>>y>>z;
        if(z%400==0||(z%4==0&&z%100!=0)) lep=1;
        else lep =0;
        n = get(x,y,lep)+262;

        n%=(365+lep);
//        cout<<"Here:"<<n<<endl;
        z-=594;
        if(y>4||(y==4&&x>=14)) z++;
        if(n==0) x=30,y=12;
        else
        {
            m=1;
            while(n>(xx[m]+(m==11?lep:0)))
            {
                n-=(xx[m]+(m==11?lep:0));
                m++;
            }
            x=n;
        }
        csco
        cout<<x<<", "<<months[m]<<", "<<z<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
