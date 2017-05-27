/**
* H:\Dropbox\Code\Code Jam\APAC 2015\Round B\Problem A. Travel.cpp
* Created on: 2015-09-20-11.14.20, Sunday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 505
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("A-large-practice.in","r",stdin)
#define fwrite freopen("A-large-practice.txt","w",stdout)
#define inf (1e9)
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

vector<int>adj[sz];
vector< vector<int> >cost[sz];
int node[sz][24];//,par[sz];

struct junc{
    int u, w, hh;
    junc(){}
    junc(int a,  int c, int hw)
    {
        u = a;
        w = c;
        hh = hw;
    }
    bool operator < (const junc &p) const
    {
        return w > p.w;
    }
};
priority_queue<junc>data;
int dijkstra(int s, int e, int hh)
{

    node[s][hh] = 0;
    data.push(junc(s,0,hh));
    junc p;
    int fromH, toH;
    while(!data.empty())
    {
        p = data.top();

        for (int i = 0; i<adj[ p.u ].size(); i++)
        {
            for (int j = 0; j<1; j++)
            {
                fromH = (p.hh+j)%24;
                toH = (fromH+ cost[p.u][i][ fromH ])%24;

                if(node[p.u][p.hh] + cost[p.u][i][ fromH ]  + j < node[ adj[p.u][i] ][ toH ])
                {
                     node[ adj[p.u][i] ][ toH ]= node[p.u][p.hh] + cost[p.u][i][ fromH ]  + j;
//                    par[adj[p.u][i]]=p.u;
//                    node[ adj[p.u][i] ] = node[p.u] + cost[p.u][i];

                    data.push(junc(adj[p.u][i],node[ adj[p.u][i] ][ toH ] , toH));

//                    data.push(junc(adj[p.u][i], node[ adj[p.u][i] ]));
                }
            }

        }
        data.pop();
    }

    int mn = inf;

    for (int i = 0; i<24; i++) //cout<<"|"<<node[e][i]<<"|"<<endl;
        mn = min(node[e][i],mn);

    return mn;
}



int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    int t, n, m, cas=1,x,y,inp,k;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    vector<int>temp(24,0);
    scanf("%d", &t);

    while(t--)
    {
        printf("Case #%d:",cas++);

        scanf("%d %d %d", &n, &m, &k);

        for (int i = 0; i<=n; i++)
        {
            adj[i].clear(), cost[i].clear();
//            par[i]=-1;
            for (int j = 0; j<24; j++)
                node[i][j]=inf;
        }



        for (int i = 0; i<m; i++)
        {
            scanf("%d %d", &x, &y);
            for (int j = 0; j<24; j++)
            {
                scanf("%d", &inp);
                temp[j] = inp;
            }
            adj[x].pb(y);
            adj[y].pb(x);
            cost[x].pb(temp);
            cost[y].pb(temp);
        }

//        for (int i = 1; i<=3; i++)
//        {
//            for (int j = 0; j<adj[i].size(); j++)
//            {
//                cout<<i<<" -> "<<adj[i][j]<<":";
//
//                for (int k = 0; k<24; k++)
//                    cout<<" "<<cost[i][j][k];
//                    cout<<endl;
//            }
//
//        }return 0;

        for (int i = 0; i<k; i++)
        {
            for (int kk = 0; kk<=n; kk++)
                for (int j = 0; j<24; j++)
                    node[kk][j]=inf;
            scanf("%d %d", &x, &y);
            int ans = dijkstra(1,x,y);
            if(ans>=inf) ans = -1;
            printf(" %d", ans);
        }

        puts("");
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
