/**
* E:\Dropbox\Code\Code Jam\2016\Round 1C 2016\Problem A. Senate Evacuation.cpp
* Created on: 2016-05-08-15.04.40, Sunday
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
#define allr(a) a.rbegin(),a.rend()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("A-large.in","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case #%d: ", cas++);
#define csco cout<<"Case #"<<cas++<<":";
#define mod 1000000007

#ifdef ENAM
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...)
#endif

ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

vector< pair<int,int> >v;

void print(vector< pair<int,int> > a)
{
    cout<<"------------------>\n";
    for (auto &x: a)
        cout<<x.first<<" : "<<x.second<<endl;
}

int main()
{
#ifdef ENAM
      fread;
  fwrite;
#endif // ENAM
	_
	int cas = 1,t,n,m,x,y,z;
	char ch;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

		cin>>t;

		while(t--)
        {
            cin>>n;
            v.clear();
            for (int i = 0; i<n; i++)
            {
                cin>>m;
                v.pb({m,i});
            }csco
            while(1)
            {
                sort(allr(v));
                if(v[0].first==0)break;
//                print(v);
                x = 0;
                for (int i = 0; i<n; i++)
                    x+=v[i].first;
                if(v[0].first>=2&&(v[0].first-2)*2<=x-2&&v[1].first*2<=x-2)
                {
                    ch = (v[0].second+'A');
                    cout<<" "<<ch<<ch;
                    v[0].first-=2;
                }
                else if(v[0].first>=1&&v[1].first>=1&&(v[0].first-1)*2<=x-2 && (v[1].first-1)*2<=x-2 && (v.size()<3 || (v[2].first*2<=x-2 ) ) )
                {
                    ch = (v[0].second+'A');
                    cout<<" "<<ch;
                    v[0].first--;
                    ch = (v[1].second+'A');
                    cout<<ch;
                    v[1].first--;
                }
                else if ((v[0].first-1)*2<=x-1 && v[1].first*2<=x-1)
                {
                    ch = (v[0].second+'A');
                    cout<<" "<<ch;
                    v[0].first--;
                }
                else assert(0);
//                cout<<" "<<(char)(v[0].second+'A');
//                v[0].first--;
//                if(v[1].first) {cout<<(char)(v[1].second+'A');v[1].first--;}
            }
            cout<<"\n";
        }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
