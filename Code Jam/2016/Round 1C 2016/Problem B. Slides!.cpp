/**
* E:\Dropbox\Code\Code Jam\2016\Round 1C 2016\Problem B. Slides!.cpp
* Created on: 2016-05-08-15.56.38, Sunday
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
#define fread freopen("B-large.in","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
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

int mat[70][70];

int main()
{
#ifdef ENAM
      fread;
  fwrite;
#endif // ENAM
	_
	ll cas = 1,t,n,m,x,y,z;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

		cin>>t;

		while(t--)
        {
            cin>>n>>m;
            csco
            x = (1LL<<(n-2));
            if(m>x)
            {
                cout<<"IMPOSSIBLE\n";
                continue;
            }
            cout<<"POSSIBLE\n";
            clr(mat,0);
            for (int i = 1; i<n; i++)
                for (int j = i+1; j<n; j++)
                    mat[i][j]=1;
            y = m-1;
//            cout<<"d="<<y<<endl;
            mat[0][n-1]=1;
            for (int i = n-3,j=1; i>=0; i--,j++)
            {
                if(y&(1LL<<i))
                {
//                    cout<<i<<" : "<<j<<endl;
                    mat[0][j]=1;
                }
            }




            for (int i = 0; i<n; i++)
            {
                for (int j = 0; j<n; j++)
                    cout<<mat[i][j];
                cout<<"\n";
            }

        }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
