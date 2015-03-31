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

struct node
{
    int num, dist, connected;
    node() {}
    node(int a, int b)
    {
        num = a;
        dist = b;
        connected=0;
    }

    bool operator < (const node& p) const
    {
        return dist > p.dist;
    }

};

struct edge
{
    int x, y;
    edge() {}
    edge(int a, int b)
    {
        x = a;
        y = b;
    }
};

vector<node>v;
vector<edge>ans;


bool comp(node a, node b)
{
    return a.dist<b.dist;
}
bool comp2(edge a, edge b)
{
    return (a.x==b.x?a.y<b.y:a.x<b.x);
}
priority_queue<node>q;

int main()
{
    int t, n, m, cas=1, k, len;
    bool flag = true;
    node c,d;
    scanf("%d %d", &n, &k);

    for (int i = 0; i<n; i++)
    {
        scanf("%d", &m);
        v.pb(node(i+1,m));
    }

    sort(v.begin(), v.end(), comp);
    len = v.size();
    if(v[0].dist) flag = false;
    else q.push(v[0]);

    for (int i = 1; i<len; i++)
    {
        if(q.empty())
        {
            flag = false;
            break;
        }
        c = q.top();
        q.pop();
        d = v[i];

        if(c.dist+1==d.dist)
        {
            c.connected++;
            d.connected++;
            if(c.connected<k) q.push(c);
            if(d.connected<k) q.push(d);
//            c.num<d.num?ans.pb(edge(c.num, d.num)):
                ans.pb(edge(d.num, c.num));
        }
        else if(c.dist<d.dist)
        {
            i--;
        }
        else
        {
            flag = false;
            break;
        }
    }

    if(flag)
        {
//            sort(ans.begin(), ans.end(), comp2);
            len = ans.size();
            printf("%d\n", len);

            for (int i = 0; i<len; i++)
                printf("%d %d\n", ans[i].x, ans[i].y);
        }
        else
        {
            printf("-1\n");
        }

    return 0;
}
