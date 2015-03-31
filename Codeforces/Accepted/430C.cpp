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

#define sz 100055
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
#define mod 1000000007
using namespace std;

int par[sz], init[sz], goal[sz];

vector<int> adj[sz], ans;
void rec(int n, int chng, int chngp)
{
    int mask = ((goal[n]^init[n])^chngp);
    if(mask) ans.pb(n);
    for (int i = 0; i<adj[n].size(); i++)
    {
        if(adj[n][i]==par[n]) continue;
        par[ adj[n][i] ] = n;
        rec(adj[n][i],mask^chngp,chng);
    }

    return;
}



int main()
{
    #ifdef ENAM
    	fread;
//	fwrite;
    #endif // ENAM
    int n, m, l;
    scanf("%d", &n);
    for (int i = 1; i<n; i++)
    {
        scanf("%d %d", &l, &m);
        adj[l].pb(m);
        adj[m].pb(l);
    }
    for (int i = 1; i<=n; i++)
        scanf("%d", &init[i]);
    for (int i = 1; i<=n; i++)
        scanf("%d", &goal[i]);
    rec(1,0,0);
    m = ans.size();
    printf("%d\n",m);

    for (int i = 0; i<m; i++)
        printf("%d\n",ans[i]);
    return 0;
}
