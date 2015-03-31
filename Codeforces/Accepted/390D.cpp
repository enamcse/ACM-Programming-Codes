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

#define sz 55
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

int rr[] = {0,0,-1,1};
int cc[] = {1,-1,0,0};

int n, m,cnt=1;

struct point{
    int a, b, k;
};

vector<point>order;
pair<int,int>par[sz][sz];

int grid[sz][sz];

void bfs(int k)
{
    grid[0][0] = cnt++;
    point p, s;
    p.a=0;
    p.b=0;
    p.k=1;
    par[0][0] = make_pair(-1,-1);

    queue<point>q;
    q.push(p);
    order.pb(p);
    int u, v;
    while(!q.empty())
    {
        if(cnt>k) return;
        p = q.front();

        for (int i = 0; i<4; i++)
        {
            u = p.a+rr[i];
            v = p.b+cc[i];
            if(u<0||v<0||u>=n||v>=m) continue;
            if(!grid[u][v])
            {
                s.a= u;
                s.b = v;
                s.k = cnt++;
                q.push(s);
                order.pb(s);
                grid[u][v] = grid[p.a][p.b]+1;
                par[u][v] = make_pair(p.a,p.b);
                if(cnt>k) return;
            }
        }
        q.pop();
    }
    return;
}


void find_path(int x, int y)
{
    if(par[x][y].first==-1)
    {
        cout<<"("<<1<<","<<1<<") ";
        return;
    }
    find_path(par[x][y].first, par[x][y].second);
    cout<<"("<<x+1<<","<<y+1<<") ";
    return;
}

bool comp(point a, point b)
{
    return a.k>b.k;
}

int main()
{
    int t,k,  cas=1, len;
    cin>>n>>m>>k;
    bfs(k);
    len=0;
    sort(order.begin(), order.end(), comp);
    t = order.size();
    for (int i = 0; i<t; i++)
        len+= (grid[order[i].a][order[i].b]);

    cout<<len<<endl;

    for (int i = 0; i<t; i++)
    {
        find_path(order[i].a, order[i].b);
        cout<<endl;
    }

    return 0;
}
