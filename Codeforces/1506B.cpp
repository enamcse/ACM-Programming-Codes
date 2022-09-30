/**
* C:\Users\maqas\Dropbox\Code\Codeforces\1506B.cpp
* Created on: 2021-03-28-09.13.45, Sunday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
using namespace std;
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

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}


int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	int cas = 1,t,n,m,x,y,z, k, res=0, i;
	string s;

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

	cin >> t;

	while(t--)
    {
        cin >> n >> k;
        cin.ignore();
        cin >> s;

        for (i = 0; i<n; i++)
            if(s[i] == '*')
            {
                x = i;
                break;
            }

        for (i = n-1; i>=0; i--)
            if(s[i] == '*')
            {
                y = i;
                break;
            }
        res = 0;
        m = x;
        for (i = x; i<=y; i+=k)
        {
            while(s[i]!='*'&&m<i) i--;
            if(s[i]=='*') res++;
            m = i;
        }
        i-=k;
        if(i!=y && i!=x) res++;
        if(x!=y&&res<2) res++;
        cout << res << "\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
