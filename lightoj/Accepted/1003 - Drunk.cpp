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

#define sz 20001
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

int cnt,indeg[sz];
vector<int>adj[sz];
map<string,int>mp;

int incoming(int i, int j)
{
    return binary_search(adj[i].begin(),adj[i].end(),j);
}

bool topsort()
{
    queue<int>q;
    int deg=0;
    for (int i = 0; i<cnt; i++)
        if(!indeg[i])q.push(i),deg++;
    int n,len;
    while(!q.empty())
    {
        n = q.front();
        len = adj[n].size();
        for (int i = 0; i<len; i++)
            if(--indeg[ adj[n][i] ]==0) q.push(adj[n][i]),deg++;
        q.pop();
    }

    return cnt==deg;
}


int main()
{
    int m,t,cas=1,x1,x2,n;
    char n1[20],n2[20];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &m);
        mp.clear();
        cnt=0;
        clr(indeg,0);
        n = (m<<1);
        for (int i = 0; i<n; i++)
            adj[i].clear();

        for (int i = 0; i<m; i++)
        {
            scanf("%s %s", n1,n2);
            if(mp.find(n1)==mp.end())
            {
                x1=cnt;
                mp[n1]=cnt++;
            }
            else x1=mp[n1];
            if(mp.find(n2)==mp.end())
            {
                x2=cnt;
                mp[n2]=cnt++;
            }
            else x2=mp[n2];
            adj[x1].pb(x2);
            indeg[x2]++;
        }

        if(topsort())printf("Case %d: Yes\n",cas++);
        else printf("Case %d: No\n",cas++);
    }

	return 0;
}
/*
1
3
soda wine
water wine
wine water

2
2
soda wine
water wine
3
soda wine
water wine
wine water
*/
