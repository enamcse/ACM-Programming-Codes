#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

///1 based graph + component

const int MAX = 100050;

int id,distime[MAX],height[MAX],color[MAX],group_id[MAX],com,in_degree[MAX];
vector<int> knode[MAX];
bool isK[MAX];
bool isCK[MAX];
vector<int> adj[MAX];
vector<int> nadj[MAX];
stack<int> S;

void init(int n)
{
    id=com=0;
    clrall(color,0);
    clrall(isK,0);
    clrall(isCK,0);
    clrall(in_degree,0);
    while(!S.empty()) S.pop();
    for(int i=0;i<=n;i++) adj[i].clear(),nadj[i].clear(),knode[i].clear();
    return ;
}

void scc(int u)
{
    color[u]=1;
    S.push(u);
    distime[u]=height[u]=id++;
    int v;
    for(int i=0;i<SZ(adj[u]);i++)
    {
        v=adj[u][i];
        if(color[v]==1) height[u]=min(height[u],distime[v]);
        else if(color[v]==0)
        {
            scc(v);
            height[u]=min(height[u],height[v]);
        }
    }
    if(height[u]==distime[u])
    {
        com++;
        do
        {
            v=S.top();
            S.pop();
            color[v]=2;
            group_id[v]=com;
            if(isK[v])
            {
                isCK[com]=true;
                knode[com].psb(v);
            }
        }
        while(v!=u);
        if(!knode[com].empty()) sort(all(knode[com]));
    }
    return ;
}

void makeNewGraph(int n)
{
    for(int u=1;u<=n;u++)
    {
//        deb("u : ",u," g u : ",group_id[u]);
        for(int j=0;j<SZ(adj[u]);j++)
        {
            int v = adj[u][j];
            if(group_id[u]!=group_id[v])
            {
                nadj[group_id[u]].psb(group_id[v]);
//                deb(u,v,group_id[u],group_id[v]);
                in_degree[group_id[v]]++;
            }
        }
    }
    return ;
}

void TarjanSCC(int n)
{
    for(int i=1;i<=n;i++) if(!color[i]) scc(i);
    return ;
}


vector<pair<int,int> > kv;

int lvl[MAX];

bool bfssol()
{
    queue<pair<int,int> > Q;
    kv.clear();
    clrall(lvl,0);
    for(int i=1;i<=com;i++)
    {
        if(in_degree[i]==0){
            Q.push(mp(i,isCK[i]));
            if(isCK[i])
            {
                kv.psb(mp(1,i));
//                deb("in ",i);
            }
        }
    }

    while(!Q.empty())
    {
        int u=Q.front().fs;
        int lv = Q.front().sc;
        Q.pop();
        for(int j=0;j<SZ(nadj[u]);j++)
        {
            int v = nadj[u][j];
            if(in_degree[v])
            {
                in_degree[v]--;
                lvl[v]=max(lvl[v],lv+isCK[v]);
                if(in_degree[v]==0)
                {
                    if(isCK[v])
                    {
                        Q.push(mp(v,lvl[v]));
                        kv.psb(mp(lvl[v],v));
                    }
                    else Q.push(mp(v,lvl[v]));
                }
            }
        }
    }
    sort(all(kv));
//    deb("inkv *** ",kv[0].sc,kv[0].fs,lvl[kv[0].sc]);
    for(int i=1;i<SZ(kv);i++)
    {
//        deb("inkv *** ",kv[i].sc,kv[i].fs,lvl[kv[i].sc]);
        if(kv[i].fs==kv[i-1].fs) return false;
    }
    return true;
}

vector<int> res;

int main()
{
    int t,n,m,u,v,k;
    SF("%d",&t);
    while(t--)
    {
        SF("%d %d %d",&n,&m,&k);
        init(n);
        for(int i=0;i<k;i++)
        {
            SF("%d",&u);
            isK[u]=true;
        }
        while(m--)
        {
            SF("%d %d",&u,&v);
            adj[u].psb(v);
        }
        TarjanSCC(n);
        makeNewGraph(n);
        if(!bfssol())
        {
            PF("-1\n");
        }
        else
        {
            res.clear();
            for(int i=0;i<SZ(kv);i++)
            {
                u=kv[i].sc;
//                deb("in loop : ",u,SZ(knode[u]));
                for(int j=0;j<SZ(knode[u]);j++)
                    res.psb(knode[u][j]);
            }
//            deb("size of res : ",SZ(res));
            assert(SZ(res)==k);
            int tt=SZ(res);
            for(int i=0;i<tt;i++)
            {
                PF("%d%c",res[i]," \n"[i==tt-1]);
            }
        }
    }
    return 0;
}
/*
4
4 3 2
3 4
1 2
2 1
1 3
*/

