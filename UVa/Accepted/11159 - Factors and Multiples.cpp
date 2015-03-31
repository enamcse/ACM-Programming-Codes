/**
* H:\Dropbox\Code\UVa\11159 - Factors and Multiples.cpp
* Created on: 2015-02-04-02.35.01, Wednesday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 205
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
int t, n, m, counter=1, visited[sz], par[sz];

int dfs(int u)
{
    if(visited[u]==counter) return 0;
    visited[u] = counter;
    int len = adj[u].size();
    for (int i = 0; i<len; i++)
    {
        int v = adj[u][i];
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
        counter++;
    }

    return ret;
}

int arr[sz/2];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int cas=1,x;
    _

    cin>>t;

    while(t--)
    {
        cin>>n;

        for (int i=0; i<n; i++)
            cin>>arr[i];
        cin>>m;
        for (int i = 0; i<n+m; i++)
                adj[i].clear();

        for (int i=0; i<m; i++)
        {
            cin>>x;
            for (int j = 0; j<n; j++)
            {
                if(x==0&&arr[j]==0)adj[j].pb(i+n);
                else if(x==0) adj[j].pb(i+n);
                else if(arr[j]!=0 && x%arr[j]==0) adj[j].pb(i+n);

            }

        }

        n+=m;
        cout<<"Case "<<cas++<<": "<<BPM()<<"\n";

    }

   return 0;
}
