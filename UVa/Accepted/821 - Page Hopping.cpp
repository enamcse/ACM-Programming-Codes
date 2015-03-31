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

#define sz 105
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

int graph[sz][sz];
set<int>s;

double floyed_warshall()
{
    set<int>::iterator it = s.begin();
    int mn = *it,mx, sum=0;
    while(it!=s.end())
    {
        mx = *it;
        it++;
    }
    for (int k = mn; k<=mx; k++)
        for (int i = mn; i<=mx; i++){
                if(i==k) continue;
            for (int j = mn; j<=mx; j++)
                if(graph[i][k]&&graph[k][j])
                {
                    if(i==j||j==k) continue;
                    if(graph[i][j])graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
                    else graph[i][j] = graph[i][k]+graph[k][j];
                }
        }
    for (int i =mn; i<=mx; i++)
        for (int j = mn; j<=mx; j++)
            sum+=graph[i][j];
            mn = s.size();
    return sum/(mn*(mn-1)*1.0);
}

int main()
{
    int a,b, cas=1;
    while(~scanf("%d %d", &a, &b))
    {
        s.clear();
        clr(graph,0);
        if(!a&&!b) break;

        while(a||b)
        {
            graph[a][b]=1;
            s.insert(a);
            s.insert(b);
            scanf("%d %d", &a, &b);
        }
        printf("Case %d: average length between pages = %.3lf clicks\n",cas++,floyed_warshall());
    }
	return 0;
}
