/**
* H:\Dropbox\Code\lightoj\1176 - Getting a T-shirt.cpp
* Created on: 2015-02-08-23.01.59, Sunday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <stdio.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int INF = 2000000000;
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

map<string,int>mpp;


int main()
{
    mpp["XXL"] = 7;
    mpp["XL"] = 2;
    mpp["L"] = 3;
    mpp["M"] = 4;
    mpp["S"] = 5;
    mpp["XS"] = 6;

    Dinic *flow;
    int t, n, m, source=0, sink=1, x, y, z, ans, cas=1;
    char a[10];
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &n, &m);
        flow = new Dinic(8+m);

        for (int i = 2; i<=7; i++)
            flow->AddEdge(source, i, n);

        for (int i = 0; i<m; i++)
        {
            flow->AddEdge(i+8, sink, 1);
            scanf(" %s", a);
            x = mpp[a];
            flow->AddEdge(x, i+8, 1);
            scanf(" %s", a);
            y = mpp[a];
            flow->AddEdge(y, i+8, 1);
        }

        ans = flow->GetMaxFlow(source, sink);
        delete flow;
        if(ans==m) printf("Case %d: YES\n", cas++);
        else printf("Case %d: NO\n", cas++);
    }
    return 0;
}
