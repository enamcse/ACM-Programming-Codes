/**
* H:\Dropbox\Code\lightoj\1094 - Farthest Nodes in a Tree.cpp
* Created on: 2015-02-01-04.44.31, Sunday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 30005
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

vector<int>adj[sz], cost[sz];
int par[sz];

pair<int,int> dfs(int pos)
{
    int len = adj[pos].size();
    pair<int,int>ans = make_pair(0,pos),x;
    for (int i =0; i<len; i++)
    {
        if(adj[pos][i] == par[pos]) continue;
        par[ adj[pos][i] ] = pos;
        x = dfs(adj[pos][i]);
        if(x.first+cost[pos][i] > ans.first)
        {
            ans.first = x.first+cost[pos][i];
            ans.second = x.second;
        }
    }
    return ans;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,x,y,z,a,b;
    _

	cin>>t;
	while(t--)
    {
        cin>>n;
        for (int i = 0; i<n; i++)
            adj[i].clear(), cost[i].clear();

        for (int i = 1; i<n; i++)
        {
            cin>>x>>y>>z;
            adj[x].pb(y);
            adj[y].pb(x);
            cost[x].pb(z);
            cost[y].pb(z);
        }

        par[0]=-1;
        pair<int,int> node = dfs(0);
        a = node.second;
        b = node.first;
        par[a]=-1;
        node = dfs(a);
        b = max(b,node.first);

        cout<<"Case "<<cas++<<": "<<b<<"\n";

    }


   return 0;
}
