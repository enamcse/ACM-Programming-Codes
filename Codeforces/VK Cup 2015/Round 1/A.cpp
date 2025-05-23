/**
* G:\Laptop\Dropbox\Code\Codeforces\VK Cup 2015\Round 1\A.cpp
* Created on: 2015-03-21-20.23.25, Saturday
* Verdict: Solved
* Author: Enamul Hassan + Rumman Mahdi ;)
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

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

map<int,int>to,from;
int cnt=1;
int mat[205][205];
int n, k, u, v;
vector<int>adj[205];
map<int,vector<int> >ans;
int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM

    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n>>k;

    for (int i = 0; i<n; i++)
    {
        cin>>u>>v;
        if(to.count(u)==0) {to[u]=cnt;from[cnt]=u;cnt++;}
        if(to.count(v)==0) {to[v]=cnt;from[cnt]=v;cnt++;}
        u = to[u];
        v = to[v];
        mat[u][v] = mat[v][u] = 1;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i<cnt; i++)
    {
        vector<int>res;
        int total=adj[i].size();
        for (int j = 1; j<cnt; j++)
        {
            if(i==j) continue;
            int o;
            if(mat[i][j])continue;
            int fr = 0;
//            if(!mat[i][j])
//            {
            for (o = 0; o<total; o++)
                if(mat[ adj[i][o] ][j])fr++;
            double percent = fr*100;
//            cerr<<i<<" L "<<j<<" H "<<total<<":"<<fr<<endl;
            percent/=(total*1.0);
            if(percent>=k)
                res.pb(from[j]);
//            }
        }
        sort(all(res));
        ans[ from[i] ] = res;
    }

    for (auto it = ans.begin(); it!=ans.end(); it++)
    {
        cout<<it->first<<":";
        vector<int> &res = it->second;
        cout<<" "<<res.size();
        for (int i = 0; i<(int)res.size(); i++)
            cout<<" "<<res[i];

        cout<<"\n";
    }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
