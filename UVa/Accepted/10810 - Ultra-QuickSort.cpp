/**
* E:\Dropbox\Code\UVa\Accepted\10810 - Ultra-QuickSort.cpp
* Created on: 2016-06-18-06.44.51, Saturday
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

ll inv;

vector<int> merge_sort(vector<int> &v)
{
    if(v.size()==1) return v;
    int n = v.size()/2;
    vector<int> v1(v.begin(),v.begin()+n),  v2(v.begin()+n,v.end());
    v1 = merge_sort(v1);
    v2 = merge_sort(v2);
    int n1 = v1.size(), n2 = v2.size();
    v.clear();
    int p2,p1 = p2 = 0;
    while(p1<n1 || p2<n2)
    {
        if(p1==n1) v.pb(v2[p2++]);
        else if(p2==n2) v.pb(v1[p1++]);
        else
        {
            if(v1[p1]<=v2[p2]) v.pb(v1[p1++]);
            else
            {
                inv+=n1-p1;
                v.pb(v2[p2++]);
            }
        }
    }
    return v;
}
int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
	_
	int cas = 1,t,n,m,y,z;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    while(cin>>n&&n){
    inv = 0;
    vector<int>v(n);
    for(auto &x: v) cin>>x;
    merge_sort(v);
    cout<<inv<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
