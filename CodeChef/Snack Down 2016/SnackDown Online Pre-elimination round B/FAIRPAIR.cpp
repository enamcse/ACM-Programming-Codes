/**
* E:\Dropbox\Code\CodeChef\Snack Down 2016\SnackDown Online Pre-elimination round B\FAIRPAIR.cpp
* Created on: 2016-06-13-01.07.27, Monday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((ll)a.size())
#define sz 200005
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
#define csco cout<<"Case "<<cas++<<": ";
#define mod 1000000007

#ifdef ENAM
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...)
#endif

using namespace std;
#define MAX 2005
vector<int>adj[MAX];
int arr[MAX],m,n,cc;
int dfs(int u);
int par[MAX];
int col[MAX];
int MAX_BMP(int n)
{
    int ret = 0, i;
//    clr(par, -1);
    for(i = 0; i < n; i++)
    {
//        clr(col, 0);
        cc++;
        if(dfs(i)) ret++;
    }
    return ret;
}
int dfs(int u)
{
    if(col[u]==cc)
        return false;
    col[u] = cc;
    for(int i = 0; i < SZ(adj[u]); i++)
    {
        int v = adj[u][i];
        if(par[v] == -1 || dfs(par[v]))
        {
            par[v] = u;//err<<v <<" >> "<<u<<endl;
            return true;
        }
    }
    return false;
}


int main()
{
#ifdef ENAM
//      fread;
//  fwrite;
#endif // ENAM
    _
    int cas = 1,t,x,y,z;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    cin>>t;
//t--;
    while(t-->0)
    {
        cin>>n;
        m = (n<<1);
        for (int i = 0; i<m; i++)
            adj[i].clear(),par[i]=-1;

        for (int i = 0; i<m; i++)
        {
            cin>>arr[i];
//            if(i>=n) arr[i]=-arr[i];
        }

        for (int i = 0; i<m; i++)
        {
            x = i>=n?m:n;
            for (int j = i>=n?n:0; j<x; j++)
            {
                if(arr[i]!=arr[j]) adj[i].pb(j);
            }
        }


        cout<<n-MAX_BMP(n)<<"\n";

        for(int i = 0; i<n; i++)
//            cout<<par[i]<<" \n"[i==m-1];
            cout<<(par[i]==-1?i:par[i])+1<<" \n"[i==n-1];

    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
