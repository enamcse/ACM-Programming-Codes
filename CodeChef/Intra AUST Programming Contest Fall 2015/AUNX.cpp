/**
* E:\Dropbox\Code\CodeChef\Intra AUST Programming Contest Fall 2015\AUNX.cpp
* Created on: 2016-01-22-21.32.44, Friday
* Verdict: Solved
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

string str[] = {"C","C#","D", "D#", "E", "F", "F#", "G", "G#",
"A", "A#","B"};


int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	int t, n, s,f,cas=1;
    cin>>t;

    while(t--)
    {
        cin>>f>>s;
        csco
        if(s==1||s==6)cout<<str[(4+f)%12]<<"\n";
        else if(s==2)cout<<str[(11+f)%12]<<"\n";
        else if(s==3)cout<<str[(7+f)%12]<<"\n";
        else if(s==4)cout<<str[(2+f)%12]<<"\n";
        else if(s==5)cout<<str[(9+f)%12]<<"\n";
    }
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
