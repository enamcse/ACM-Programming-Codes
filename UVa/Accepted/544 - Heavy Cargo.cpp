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

#define sz 200
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

map<string, int> m;
int graph[sz][sz], cnt;

void floyed_warshall()
{
    for (int k = 0; k<cnt; k++)
        for (int i = 0; i<cnt; i++)
            for (int j  = 0; j<cnt; j++)
                graph[i][j] = max(graph[i][j], min(graph[i][k], graph[k][j]));
}

int main()
{
    int r,n, cost,cas=1;
    char line1[sz], line2[sz];
    while(~scanf("%d %d",&n, &r)&&(n||r))
    {
        cnt = 0;
        m.clear();
        clr(graph,-1);
        for (int i = 0; i<r; i++)
        {
            scanf("%s %s %d", line1, line2, &cost);
            if(m.find(line1)==m.end()) m[line1]=cnt++;
            if(m.find(line2)==m.end()) m[line2]=cnt++;
            graph[m[line1]][m[line2]] = cost;
            graph[m[line2]][m[line1]] = cost;
        }
        floyed_warshall();
        scanf("%s %s", line1, line2);

        printf("Scenario #%d\n%d tons\n\n",cas++, graph[m[line1]][m[line2]]);
    }
	return 0;
}
