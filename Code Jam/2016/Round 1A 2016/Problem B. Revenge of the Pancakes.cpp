/**
* E:\Dropbox\Code\Code Jam\2016\Problem B. Revenge of the Pancakes.cpp
* Created on: 2016-04-09-06.25.43, Saturday
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
#define fread freopen("B-large.in","r",stdin)
#define fwrite freopen("B-large.out","w",stdout)
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

int check(string &s)
{
    for(auto x: s)
        if(x=='-') return false;
    return true;
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
//    cout<<(1<<11)<<endl;
//    for (int i = 0; i<(1<<11); i++)
//    {
//        string s="";
//        for (int j=0; j<11; j++)
//            if(i&(1<<j)) s+='+';
//            else s+='-';
//        cout<<s<<endl;
//    }
    string s;
    cin>>t;

    while(t--)
    {
        cin>>s;
        n = s.size();
        m=0;
        for (int i  = 0; i<n; i++)
        {
            if(check(s)) break;
            for (x = 0; x<n; x++)
                if(s[x]=='-'){y=x;break;}
            for (; x<n; x++)
                if(s[x]=='-'){z=x;}
                else break;
            m++;
            if(y) m++;
            for (int j = y; j<=z; j++)
                s[j]='+';
//            cerr<<i<<">>"<<s<<", y="<<y<<", z="<<z<<endl;
        }
        csco
        cout<<m<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
