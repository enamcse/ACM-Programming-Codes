/**
* E:\Dropbox\Code\CodeChef\Snack Down 2016\Qualification Round\KGOOD.cpp
* Created on: 2016-05-30-20.01.23, Monday
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

int let[26];

int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	int cas = 1,t,n,m,x,y,z,i;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    string s;
    vector<int>v;
    cin>>t;

    while(t--)
    {
        cin>>s>>m;
        clr(let,0);
        z=0;
        n = s.size();
        x=n;
        for (i = 0; i<n; i++)
            let[ s[i]-'a' ]++;
        v.clear();
        for (i=0; i<26; i++)
            if(let[i]) v.pb(let[i]);
        sort(all(v));
        for (i=0; i<v.size(); i++)
        {
            z=0;
            for (int j = 0; j<i; j++)
                z+=v[j];
            for (int j = i+1; j<v.size(); j++)
                z+=max(0,v[j]-v[i]-m);
            x=min(x,z);
        }


        cout<<x<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
