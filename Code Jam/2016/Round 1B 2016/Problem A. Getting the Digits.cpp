/**
* E:\Dropbox\Code\Code Jam\2016\Round 1B 2016\Problem A. Getting the Digits.cpp
* Created on: 2016-04-30-22.02.05, Saturday
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
#define fread freopen("A-large.in","r",stdin)
#define fwrite freopen("A-large.txt","w",stdout)
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
int let[260];
vector<int>v;
int main()
{
#ifdef ENAM
      fread;
  fwrite;
#endif // ENAM
	_
	int cas = 1,t,n,m,y,z;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
        string s;
		cin>>t;
		cin.ignore();
		while(t--)
        {
            cin>>s;
            n = s.size();
            v.clear();
            clr(let,0);
            for (auto &x:s)
                let[x]++;
            ///ZERO
            for (int i = 0; i<n; i++)
            {
                if(!let['Z']) break;
                let['Z']--;
                let['E']--;
                let['R']--;
                let['O']--;v.pb(0);
            }
            ///TWO
            for (int i = 0; i<n; i++)
            {
                if(!let['W']) break;
                let['T']--;
                let['W']--;
                let['O']--;v.pb(2);
            }
            ///FOUR
            for (int i = 0; i<n; i++)
            {
                if(!let['U']) break;
                let['F']--;
                let['O']--;
                let['U']--;
                let['R']--;v.pb(4);
            }
            ///SIX
            for (int i = 0; i<n; i++)
            {
                if(!let['X']) break;
                let['S']--;
                let['I']--;
                let['X']--;v.pb(6);
            }
            ///EIGHT
            for (int i = 0; i<n; i++)
            {
                if(!let['G']) break;
                let['E']--;
                let['I']--;
                let['G']--;
                let['H']--;
                let['T']--;v.pb(8);
            }
            ///THREE
            for (int i = 0; i<n; i++)
            {
                if(!let['H']) break;
                let['T']--;
                let['H']--;
                let['R']--;
                let['E']--;
                let['E']--;v.pb(3);
            }
            ///ONE
            for (int i = 0; i<n; i++)
            {
                if(!let['O']||!let['N']||!let['E']) break;
                let['O']--;
                let['N']--;
                let['E']--;v.pb(1);
            }
            ///FIVE
            for (int i = 0; i<n; i++)
            {
                if(!let['F']||!let['I']||!let['V']) break;
                let['F']--;
                let['I']--;
                let['V']--;
                let['E']--;v.pb(5);
            }
            ///SEVEN
            for (int i = 0; i<n; i++)
            {
                if(!let['S']||!let['E']||!let['V']) break;
                let['S']--;
                let['E']--;
                let['V']--;
                let['E']--;
                let['N']--;v.pb(7);
            }
            ///NINE
            for (int i = 0; i<n; i++)
            {
                if(!let['I']||!let['N']||!let['E']) break;
                let['N']--;
                let['E']--;
                let['I']--;
                let['N']--;v.pb(9);
            }
            sort(all(v));
            csco
            for(auto &x: v) cout<<x;
            cout<<"\n";
        }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
