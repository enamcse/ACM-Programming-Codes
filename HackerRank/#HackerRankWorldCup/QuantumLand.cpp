/**
* H:\Dropbox\Code\HackerRank\#HackerRankWorldCup\QuantumLand.cpp
* Created on: 2015-09-19-22.12.35, Saturday
* Verdict: Solved
* Author: Enamul Hassan & Rumman Mahmud Mahdi Al Masud
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SIZE(a) ((int)a.size())
#define SZ 200005
#define pb push_back
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
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007
#define VI              vector<int>
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

VI adj[SZ];//only adj should be cleared
int col[SZ],low[SZ],tim[SZ],timer;
int group_id[SZ],n,m,components;//components=number of components group_id = which node belongs to which node
stack<int>S;

double prob[SZ], res;

void scc(int u)
{
    int i,v,tem;
    col[u]=1;
    low[u]=tim[u]=timer++;
    S.push(u);
    fr(i,0,SIZE(adj[u])-1)
    {
        v=adj[u][i];
        if(col[v]==1)
            low[u]=min(low[u],tim[v]);
        else if(col[v]==0)
        {
            scc(v);
            low[u]=min(low[u],low[v]);
        }
    }

    //SCC checking...
    if(low[u]==tim[u])
    {
        double an=1.00;
        int now=0;
        do
        {
            tem=S.top();S.pop();
            group_id[tem]=components;
            an*=prob[tem];
            col[tem]=2; //Completed...
            now++;
        }while(tem!=u);
        components++;
        if(now>1) res+= an;
    }
}

int TarjanSCC() //some change may be required here
{
    int i;
    timer=components=0;
    clr(col,0);
    while(!S.empty()) S.pop();
    fr(i,0,n-1) if(col[i]==0) scc(i);
    return components;
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    scanf("%d",&n);

    for (int i = 0; i<n; i++)
    {
        scanf("%d %lf",&m, &prob[i]);
        adj[i].pb(m-1);
        prob[i]/=100.0;
    }

    TarjanSCC();

    //cout<<components<<endl;

    printf("%.2lf", res);
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
