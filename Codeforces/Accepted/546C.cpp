/**
* H:\Dropbox\Code\Codeforces\546C.cpp
* Created on: 2015-05-22-22.29.12, Friday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 200005
#define pb(a) push_back(a)
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
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

map< pair< vector<int> , vector<int> >, bool  >mpp;
bool flag;
int winner;

void print(pair< vector<int> , vector<int> > k, int c)
{
    int x, y;
    x = k.first.size();
    y = k.second.size();
    cout<<x<<":"<<y<<" C = "<<c<<endl;
    for (auto p : k.first )
        cout<<p<<":";
    cout<<endl;
    for (auto p : k.second )
        cout<<p<<";";
    cout<<endl;
}

int call(pair< vector<int> , vector<int> > &k, int cost)
{
//    print(k,cost);
    if(k.first.size()==0||k.second.size()==0)  {winner = k.first.size()==0? 2:1; return cost;}
    if(mpp.count(k)!=0) {flag = true;return -1;}
    mpp[ k ] = true;
    int x, y;
    x = k.first[0];
    y = k.second[0];
    k.first.erase(k.first.begin());
    k.second.erase(k.second.begin());
    if(x<y)
    {
        k.second.pb(x);
        k.second.pb(y);
    }
    else
    {
        k.first.pb(y);
        k.first.pb(x);
    }
    return call(k,cost+1);
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1, a, b;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    vector<int>x,y;
    cin>>n;

    cin>>a;
    for (int i = 0; i<a; i++)
        cin>>m, x.pb(m);
    cin>>b;
    for (int i = 0; i<b; i++)
        cin>>m, y.pb(m);
    pair< vector<int> , vector<int> >k = make_pair(x,y);
    t=call(k,0);
    if(flag) cout<<-1;
    else cout<<t<<" "<<winner;
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
