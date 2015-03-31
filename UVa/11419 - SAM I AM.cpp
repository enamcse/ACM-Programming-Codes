/**
* H:\Dropbox\Code\UVa\11419 - SAM I AM.cpp
* Created on: 2015-02-03-23.30.43, Tuesday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 2005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
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

vector<int>adj[sz];
int t, n, m, cas=1, e, match, visited[sz], par[sz], removed[sz];

int dfs(int u)
{
    if(visited[u]==cas || removed[u]==true) return 0;
    visited[u] = cas;
    int len = adj[u].size();
    for (int i = 0; i<len; i++)
    {
        int v = adj[u][i];
        if(removed[v]) continue;
        if(par[v]==-1 || dfs(par[v])==true)
        {
            par[v] = u;
            return 1;
        }
    }
    return 0;
}


int BPM()
{
    int ret = 0;
    clr(par,-1);
    for (int i = 0; i<n; i++)
    {
        ret+=dfs(i);
        cas++;
    }

    return ret;
}



int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int x, y;
    _

	while(cin>>n>>m>>e)
    {
        if(!n&&!m&&!e) return 0;
        vector<int>ans;
        for (int i = 0; i<n+m; i++)
            adj[i].clear();

        for (int i = 0; i<e; i++)
        {
            cin>>x>>y;
            adj[x-1].pb(n+y-1);
        }

        clr(removed, 0);

        t=match = BPM();

        for (int i = 0; i<n+m; i++)
        {
            removed[i] = 1;
            int now = BPM();
            if(now<match)
            {
                match=now;
                ans.pb(i);
            }
            else removed[i] = 0;
        }
        cout<<t;

        for (int i = 0; i<ans.size(); i++)//cout<<ans[i]<<"::";
            cout<<" "<<"cr"[ ans[i] <n ]<<(ans[i]<n?ans[i]+1: ans[i]-n+1);
        cout<<"\n";

    }

}
