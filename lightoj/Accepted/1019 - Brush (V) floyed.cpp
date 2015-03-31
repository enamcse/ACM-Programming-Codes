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
#include <stack>

#define sz 101
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e8)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

int adj[sz][sz];

int main()
{
    int t, n, m, cas=1,x,y,w;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
                adj[i][j]=inf;
            adj[i][i]=0;
        }

        for (int i = 0; i<m; i++)
        {
            scanf("%d %d %d", &x, &y, &w);
            adj[y-1][x-1]=min(w,adj[y-1][x-1]);
            adj[x-1][y-1]=min(w,adj[x-1][y-1]);
        }


        for (int k = 0; k<n; k++)
            for (int i = 0; i<n; i++)
                for (int j = 0; j<n; j++)
                    adj[i][j] =  min(adj[i][j], adj[i][k]+adj[k][j]);
        w = adj[0][n-1];
        if(w<inf) printf("Case %d: %d\n",cas++,w);
        else printf("Case %d: Impossible\n",cas++);
    }


    return 0;
}
