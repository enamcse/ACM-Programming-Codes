/**
* H:\Dropbox\Code\HDU\3586 Information Disturbing.cpp
* Created on: 2015-07-19-05.29.52, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 200005
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e8)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

vector<int>adj[1005], cost[1005];

int dp[1005], limit;

int rec(int pos, int par, int costs)
{
    if(pos!=1 && SZ(adj[pos])==1) return inf;
    int &ret = dp[pos];
    if(~ret && ret<=limit) return ret;
    ret = inf;

    int now = 0;

    for (int i = 0; i<SZ(adj[pos]); i++)
    {
        if(adj[pos][i] == par) continue;
        now = max( now, rec(adj[pos][i],pos,cost[pos][i]));
    }

//    cerr<<" ha : "<< pos<<" " << par <<" " << costs << " : " << now <<" " << ret <<endl;
    now=now<=limit?now:inf;
    ret=min(ret,now);
    return ret;
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,x,y,z;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    while(cin>>n >> m && n|m)
    {
        clr(dp,-1);
        limit = 1000;

        for (int i = 1; i<=n; i++)
            adj[i].clear(),cost[i].clear();

        rec(1,-1,inf);



        for (int i = 0; i<n-1; i++)
        {
            cin>>x>>y>>z;
            adj[x].pb(y);
            cost[x].pb(z);
        }

        if(n==1) cout<< -1 << "\n";
        else
        {
            int mid, l = 1, r = 1000, ans=-1;

            while(l<=r)
            {
                limit = (l+r)/2;
                clr(dp,-1);
                if(rec(1,-1,inf)<inf) r = limit-1,ans = limit;
                else l = limit+1;
            }

            if(ans!=-1 && ans <= m) cout<< ans <<"\n";
            else cout << -1 << "\n";

        }
    }



//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
/**
5 5
1 3 2
1 4 3
3 5 5
4 2 6
0 0
*/
