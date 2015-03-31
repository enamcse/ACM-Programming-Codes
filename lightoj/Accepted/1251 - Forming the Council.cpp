//Verdict: SOLVED
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

#define sz 8005
#define SZ(s) ((int)s.size())
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define VI vector<int>
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const)
{
    ll vag_shesh=1;
    while(ghat>0)
    {
        if(ghat%2==1)
        {
            vag_shesh=(vag_shesh*sonkha)%vag_const;
        }
        ghat/=2;
        sonkha=(sonkha*sonkha)%vag_const;
    }
    return vag_shesh;
}
ll inverse_mod(ll bivajok, ll vag_const)
{
    return bigmod(bivajok,vag_const-2, vag_const);
}
using namespace std;

//0 based
VI adj[2*sz]; //2*sz for true and false argument(only adj should be cleared)
int col[2*sz],low[2*sz],tim[2*sz],timer;
int group_id[2*sz],components;//components=number of components, group_id = which node belongs to which node
bool ans[sz]; //boolean assignment ans
stack<int>S;

void scc(int u)
{
    int i,v,tem;
    col[u]=1;
    low[u]=tim[u]=timer++;
    S.push(u);
    fr(i,0,SZ(adj[u])-1)
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
            tem=S.top();
            S.pop();
            group_id[tem]=components;
            col[tem]=2; //Completed...
        }
        while(tem!=u);
        components++;
    }
}

int TarjanSCC(int n) //n=nodes (some change may be required here)
{
    int i;
    timer=components=0;
    clr(col,0);
    while(!S.empty()) S.pop();
    fr(i,0,n-1) if(col[i]==0) scc(i);
    return components;
}

//double nodes needed normally
bool TwoSAT(int n) //n=nodes (some change may be required here)
{
    TarjanSCC(n);
    int i;
    for(i=0; i<n; i+=2)
    {
        if(group_id[i]==group_id[i+1])
            return false;
        if(group_id[i]<group_id[i+1]) //Checking who is lower in Topological sort
            ans[i/2]=true;
        else ans[i/2]=false;
    }
    return true;
}

void add(int ina,int inb)
{
    adj[ina].pb(inb);
}

int complement(int n)
{
    return n^1;
}

void initialize(int n)
{
    for(int i=0; i<n; i++)
        adj[i].clear();
}


int main()
{
    //freopen("A.in","r",stdin);
//    freopen("A.out","w",stdout);
    int t,n, m, i, u, v,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d", &m, &n);
        initialize(n<<1);

        fr(i,0,m-1)
        {
            scanf("%d %d", &u, &v);
            if(u>0) u = 2*u-2;
            else u = -2*u-1;
            if(v>0) v = 2*v-2;
            else v = -2*v-1;

            add(complement(u),v);
            add(complement(v),u);
        }

        printf("Case %d: ", cas++);
        if(TwoSAT(n<<1))
        {
            puts("Yes");
            VI v;
            fr(i,0,n-1)
            {
                if(ans[i]) v.pb(i+1);
            }
            printf("%d", SZ(v));
            fr(i,0,SZ(v)-1) printf(" %d", v[i]);





            puts("");
        }
        else puts("No");
    }


    return 0;
}

