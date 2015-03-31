/**
* H:\Dropbox\Code\Codeforces\510E.cpp
* Created on: 2015-02-03-04.58.00, Tuesday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
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

const int INF = 2000000000;

vector<int>res[205];
int cnt;

struct Edge
{
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) {}
};
struct Dinic
{
    int N;
    vector <vector<Edge> > G;
    vector <Edge *> dad;
    vector<int> Q;
    Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
    void AddEdge(int from, int to, int cap)
    {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }
    long long BlockingFlow(int s, int t)
    {
        fill(dad.begin(), dad.end(), (Edge *) NULL);
        dad[s] = &G[0][0] - 1;
        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail)
        {
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge &e = G[x][i];
                if (!dad[e.to] && e.cap - e.flow > 0)
                {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if (!dad[t]) return 0;
        long long totflow = 0;
        for (int i = 0; i < G[t].size(); i++)
        {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                if (!e)
                {
                    amt = 0;
                    break;
                }
                amt = min(amt, e->cap - e->flow);
            }
            if (amt == 0) continue;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }
    long long GetMaxFlow(int s, int t) // source, sink
    {
        long long totflow = 0;
        while (long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};

int a[205];

bool prime[30005], flag[205], col[205];

void sieve()
{
    for (int i = 3; i<30005; i+=2)
        if(!prime[i])
            for (int j = i*i; j<30005; j+=i+i)
                prime[j] = true;
    for (int i = 4; i<30005; i+=2)
        prime[i]=true;
}
Dinic *flow;

void dfs(int x)
{
    if(col[x-1]) return;
    res[cnt].pb(x);
    col[x-1]=true;

    if(!flag[x-1])
    {
        for (int i = 0; i< flow->G[x].size(); i++)
        {
            if(flow->G[x][i].cap-flow->G[x][i].flow==0) dfs(flow->G[x][i].to);
        }
    }
    else
    {
        for (int i = 0; i< flow->G[x].size(); i++)
        {
            int y = flow->G[x][i].to,j;
            for (j = 0; j< flow->G[y].size(); j++)
                if(flow->G[y][j].to==x && flow->G[y][j].cap-flow->G[y][j].flow==0) break;
            if(j!=flow->G[y].size()) dfs(flow->G[x][i].to);
        }
    }
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    sieve();
    _

//    for (int i = 1; i<100; i++)
//        cout<<i<<" "<<prime[i]<<endl;


    int n, m, source=0, sink,  ans;
    cin>>n;
    sink = n+1;
    flow = new Dinic(n+2);
    for (int i = 0; i<n; i++)
    {
        cin>>a[i];
        flag[i] = a[i]%2;
        if(flag[i]==0)flow->AddEdge(source, i+1, 2);
        else flow->AddEdge(i+1, sink, 2);
    }

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            if(i==j) continue;
            if(!prime[ a[i]+a[j] ] && flag[i]==0)
                    flow->AddEdge(i+1, j+1, 1);
        }
    }
    ans = flow->GetMaxFlow(source, sink);
//    cout<<ans<<endl;
    if(ans!=n)
    {
        cout<<"Impossible";
        return 0;
    }

    for (int i = 0; i<n; i++)
        if(!col[i])
        {
            dfs(i+1);
            cnt++;
        }

    delete flow;

    cout<<cnt<<"\n";

    for (int i = 0; i<cnt; i++)
    {
        cout<<res[i].size();
        for (int j = 0; j<res[i].size(); j++)
            cout<<" "<<res[i][j];
        cout<<"\n";
    }


   return 0;
}
