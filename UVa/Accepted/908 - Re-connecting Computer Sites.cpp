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

#define sz 1000005
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

struct edge{
    int a,b,w;
    bool operator <(const edge &p) const
    {
        return w<p.w;
    }
};

vector<edge>v;
int par[sz];

void init(int n)
{
    for (int i = 0; i<n; i++)
        par[i]=i;
}

int find_par(int x)
{
    if(par[x]==x) return x;
    return par[x] = find_par(par[x]);
}

int mst(int n)
{
    sort(v.begin(),v.end());
    init(n);
    int ans=0, cnt=1,len=v.size(),a,b;
    for (int i = 0; i<len&&cnt<n; i++)
    {
        a = find_par(v[i].a);
        b = find_par(v[i].b);
        if(a!=b)
        {
            ans+=v[i].w;
            par[a]=b;
            cnt++;
        }
    }
    return ans;
}

int main()
{
    int m, n, k, sum=-2,x;
    edge now;
    while(~scanf("%d", &n))
    {
        if(sum!=-2) puts("");

        sum=0;
        for (int i = 1; i<n; i++)
        {
            scanf("%*d %*d %d",&x);
            sum+=x;
        }
        printf("%d\n",sum);
        v.clear();
        scanf("%d", &k);
        for (int i = 0; i<k; i++)
        {
            scanf("%d %d %d",&now.a,&now.b,&now.w);
            v.pb(now);
        }

        scanf("%d", &m);
        for (int i = 0; i<m; i++)
        {
            scanf("%d %d %d",&now.a,&now.b,&now.w);
            v.pb(now);
        }
        printf("%d\n", min(sum,mst(n)));
    }
	return 0;
}
