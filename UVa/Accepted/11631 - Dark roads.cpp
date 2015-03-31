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

#define sz 200100
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

int par[sz];

struct edge
{
    int x,y,cost;
    edge() {}
    edge(int a, int b, int c)
    {
        x = a;
        y = b;
        cost = c;
    }

    bool operator <(const edge &p)const
    {
        return cost>p.cost;
    }
};

void init(int n)
{
    for (int i = 0; i<n; i++)
        par[i]=i;

    return;
}

int find_par(int n)
{
    return par[n] = (par[n]==n)?n:find_par(par[n]);
}

priority_queue<edge>pq;

int mst()
{
    int sum = 0, x,y, z;

    while(!pq.empty())
    {
        x = pq.top().x;
        y = pq.top().y;
        x = find_par(x);
        y = find_par(y);
        if(x==y) sum+=pq.top().cost;
        else par[x] = y;
        pq.pop();
    }

    return sum;
}


int main()
{
    int m, n,x,y,z;
    while(~scanf("%d %d", &m, &n)&(m||n))
    {
        init(m);

        for (int i = 0; i<n; i++)
        {
            scanf("%d %d %d", &x, &y, &z);
            pq.push(edge(x,y,z));

        }


        printf("%d\n",mst());
    }
    return 0;
}

























//everybody needs header to write a code, but I need a footer too! :)
