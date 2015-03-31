//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include <set>
#include <string>
#include <stack>
#include <bitset>

#define sz 100105
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define VI              vector<int>
#define SIZE(s)         ((int)s.size())
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat>>=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;


VI adj[sz];//only adj should be cleared
int col[sz],low[sz],tim[sz],timer;
int group_id[sz],n,m,components;//components=number of components group_id = which node belongs to which node
stack<int>S;

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
        do
        {
            tem=S.top();S.pop();
            group_id[components]++;
            col[tem]=2; //Completed...
        }while(tem!=u);
        components++;
    }
    return;
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

void init(int n)
{
    for (int i = 0; i<n; i++)
        adj[i].clear();
        return;
}

ll res, mult;

int factor[sz], primes[sz], pc;
bool siv[sz];

void seive()
{
    int sq = sqrt(100100);
    for (int i = 3; i<=sq; i+=2)
        if(!siv[i])
            for (int j = i * i; j<=100100; j+=i+i)
                siv[j] = true;
    primes[pc++] = 2;
    for (int i = 3; i<=100100; i+=2)
        if(!siv[i])primes[pc++] = i;
    return;
}

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, cas=1, cnt, freq;
    seive();
    scanf("%d", &t);

    while(t--)
    {
        res = 1;
        clr(group_id,0);
        clr(factor,0);
        scanf("%d", &n);
        init(n);
        for (int i = 0; i<n; i++)
        {
            scanf("%d", &m);
            adj[i].pb(m-1);
        }
        TarjanSCC();
        for (int i = 0; i<components; i++)
        {
            cnt = 0;
            while(group_id[i]>1)
            {
                freq = 0;
                while(group_id[i]%primes[cnt]==0) freq++,group_id[i]/=primes[cnt];
                factor[cnt] = max(factor[cnt], freq);
                cnt++;
            }
        }

        for (int i = 0; i<pc; i++)
            for (int j = 0; j<factor[i]; j++)
                res=(res*primes[i])%mod;


        printf("%lld\n", res);
    }

    return 0;
}
