/**
* H:\Dropbox\Code\Codeforces\545E.cpp
* Created on: 2015-05-20-00.18.47, Wednesday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 300005
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

using namespace std;

vector<int>adj[sz],cost[sz];
int node[sz], par[sz];
ll weight;
struct junc
{
    int u, w;
    junc() {}
    junc(int a, int c)
    {
        u = a;
        w = c;
    }
    bool operator < (const junc &p) const
    {
        return w > p.w;
    }
};

priority_queue<junc>data;
int dijkstra(int s)
{
    node[s] = 0;
    data.push(junc(s,0));
    junc p;
    while(!data.empty())
    {
        p = data.top();
        for (int i = 0; i<adj[ p.u ].size(); i++)
        {
            if(node[p.u]+ cost[p.u][i]< node[ adj[p.u][i] ])
            {
                par[ adj[p.u][i] ]= p.u;
                node[ adj[p.u][i] ] = node[p.u] + cost[p.u][i];
                data.push(junc(adj[p.u][i], node[ adj[p.u][i] ]));
            }
        }
        data.pop();
    }
}
map<pair<int,int>, int >mpp;
int cnt=1;

int www[sz];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m,c,x,y, cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n>>m;

    for (int i = 0; i<m; i++)
    {
        cin>>x>>y>>c;
        adj[x].pb(y);
        adj[y].pb(x);
        cost[x].pb(c);
        cost[y].pb(c);
        www[cnt]=c;
        mpp[make_pair(x,y)]=cnt++;
    }

    cin>>x;

    dijkstra(x);
    vector<int>ans;
    for (auto it : mpp )
    {
        x = it.first.first;
        y = it.first.second;
        if(par[x]==y||par[y]==x)
        {
            weight+=www[it.second];
            ans.pb(it.second);
        }
    }
    cout<<weight<<"\n";

    n = ans.size();

    for (int i = 0; i<n; i++)
        cout<<ans[i]<<" \n"[i==n-1];


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
