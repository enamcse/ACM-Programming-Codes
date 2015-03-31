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

struct point{
    double x;
    double y;
};

double graph[sz][sz];
int n;
void floyed_warshall()
{
    for (int k = 0; k<n; k++)
    {
        for (int i = 0; i<n; i++)
        {
            if(i==k) continue;
            for (int j = 0; j<n; j++)
            {
                if(i==j||j==k) continue;
                graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
            }
        }

    }
    return;
}

int main()
{
    int u,v, cas=1;
    point p[sz];
    while(~scanf("%d",&n)&&n)
    {
        for (int i = 0; i<n; i++)
            scanf("%lf %lf", &p[i].x, &p[i].y);
        for (int i = 0; i<n; i++)
            for (int j = 0; j<n; j++)
                graph[i][j]=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
        floyed_warshall();
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",cas++, graph[0][1]);
    }
	return 0;
}
