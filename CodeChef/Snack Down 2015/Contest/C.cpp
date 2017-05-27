/**
* E:\MyJudge\icpc2015-practice\C.cpp
* Created on: 2015-06-24-16.21.29, Wednesday
* Verdict: Solved
* Author: Enamul Hassan
* Special Thanks to: Rumman Mahmud Mahdi Al-Masud
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
#define inf (0x3fffffffffffffff)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pii 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

///V*E^2 Complexity
///number of augment path * (V+E)
///Base doesn't matter

const int MAXN = 350;///total nodes
const int MAXM = 120200;///total edges

int edges;
///edge info
int last[MAXN];
int PREV[MAXM],head[MAXM];
ll Cap[MAXM];
ll Cost[MAXM];

ll Flow[MAXN];
int edgeNo[MAXN];
ll dist[MAXN];
int par[MAXN];
bool visited[MAXN];

void init(int N)
{
    memset(last,-1,sizeof(int)*N);
    edges=0;
}

void AddEdge(int u,int v,ll cap,ll cost)
{
    head[edges]=v;
    PREV[edges]=last[u];
    Cap[edges]=cap;
    Cost[edges]=cost;
    last[u]=edges++;

    head[edges]=u;
    PREV[edges]=last[v];
    Cap[edges]=0;
    Cost[edges]=-cost;
    last[v]=edges++;
}

queue<int> Q;
pair<ll,ll> SPFA(int S,int E,int N) //source,destination,number of nodes (give more for safety)
{
    ll totFlow=0,totCost=0;
    while(!Q.empty()) Q.pop();
    ll u,v,cap,cost;
//    int cc = 0;
    while(true)
    {
//        if(cc==12) break;
//        cc++;
        Flow[S]=inf;
//        cout<<Flow[S]<<endl;
//        memset(dist,0x3fffffffffffffffLL,sizeof(ll)*N);
        for(int i = 0; i<=N; i++) dist[i] = inf;
        dist[S]=0;
        memset(visited,false,sizeof(bool)*N);
        visited[S]=1;
        Q.push(S);
        while(!Q.empty())
        {
            u=Q.front();Q.pop();
            visited[u]=false;
            for(int e=last[u];e>=0;e=PREV[e])
            {
                v=head[e];
                cap=Cap[e];
                cost=Cost[e];
//                cout<<u<<" UV "<<v<<" ::::::b "<<dist[v]<<endl;
                if(cap&&dist[v]>dist[u]+cost)
                {
                    dist[v]=dist[u]+cost;
                    Flow[v]=min(Flow[u],cap);
                    edgeNo[v]=e;
                    par[v]=u;
                    if(!visited[v])
                    {
                        visited[v]=true;
//                        cout<<u<<" UV "<<v<<" cost = "<<dist[v]<<endl;
                        Q.push(v);
                    }
                }
            }
        }
        if(dist[E]==inf) break;
        totCost+=dist[E]*Flow[E];
        totFlow+=Flow[E];
        for(int i=E;i!=S;i=par[i])
        {
            Cap[edgeNo[i]]-=Flow[E];
            Cap[edgeNo[i]^1]+=Flow[E];
        }
//        cout<<totCost<<" YoY "<<totFlow<<endl;
    }
    return make_pair(totFlow,totCost);
}

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
    int n, m, source, sink, x, y, z, cost, k;
    cin>>n>>k;
    source = 0;
    init(2*n+10);
    sink = 2*n+2;

    AddEdge(0, 1, k, 0);
    AddEdge(1, sink, 1e15, 0);

    for (int i = 1; i<=n; i++)
    {
        AddEdge(i*2, i*2+1, 1, -1e12);
        AddEdge(i*2+1, sink, 1e15, 0);
    }

    for (int i = 0; i<n; i++)
    {
        for (int j = i+1; j<=n; j++)
        {
            cin>>cost;
            AddEdge(i*2+1, j*2, 1, cost);
        }
    }

    pair<ll,ll> ans = SPFA(source, sink,2*n+10);

//    cerr<<ans.first<<" "<<ans.second<<endl;

    cout<<(ll)(ans.second+ceil((1. * ans.second)/(-1e12))*(1e12));

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
