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

map<string, int>mp;
int adj[sz][sz];

void fresh(int n)
{
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
            adj[i][j]=inf;
        adj[i][i]=0;
    }
    return;
}

int solve(int n)
{
    for (int k = 0; k<n; k++)
        for (int i = 0; i<n; i++)
            for (int j = 0; j<n; j++)
                adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
    int mx=0;
    for (int i =0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            mx=max(mx,adj[i][j]);
        }
    }
    return mx;
}

int main()
{
    int p,r, no1, no2, num, cas=1, ans, i;
    char per1[1000], per2[1000];
    while(~scanf("%d %d",&p, &r)&&(p||r))
    {
        num=0;
        mp.clear();
        fresh(p);
        for (i = 0; i<r; i++)
        {
            scanf(" %s %s",per1, per2);
            if(mp.find(per1)==mp.end())
            {
                no1 = num;
                mp[per1]=num++;
            }
            else no1 = mp[per1];
            if(mp.find(per2)==mp.end())

            {
                no2 = num;
                mp[per2]=num++;
            }
            else no2 = mp[per2];
            adj[no1][no2]=adj[no2][no1]=1;
        }

        ans = solve(p);
        if(ans>=inf)
        {
            printf("Network %d: DISCONNECTED\n\n", cas++);
        }
        else printf("Network %d: %d\n\n", cas++, ans);
    }
    return 0;
}
