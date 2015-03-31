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

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
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

void init(int n)
{
    for (int i =0; i<n; i++)
    {
        for (int j =0; j<n; j++)
            adj[i][j]=inf;
        adj[i][i]=0;
    }
}

void floyed_warshall(int n)
{
    for (int k = 0; k<n; k++)
        for (int i =0; i<n; i++)
            for (int j = 0; j<n; j++)
                adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
    return;
}

int solve(int e,int n, int times)
{
    int sum=0;
    for (int i = 0; i<n; i++)
    {
         if(adj[i][e]<=times) sum++;
    }
    return sum;
}

int main()
{
    int n,t,m,e,times,a,b,tt;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d", &n, &e, &times, &m);
        init(n);
        for (int i =0; i<m; i++)
        {
            scanf("%d %d %d", &a, &b, &tt);
            adj[a-1][b-1]=tt;
        }
        floyed_warshall(n);
        printf("%d\n",solve(e-1,n,times));

        if(t)puts("");
    }
    return 0;
}
