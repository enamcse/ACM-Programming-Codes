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

#define sz 20
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

int main()
{
    int a,b,n=-20,cas=1;
    while(~scanf("%d", &n))
    {
        a=1;

        for (int i = 0; i<=20; i++)
            for (int j = 0; j<=20; j++)
                graph[i][j]=inf;
        for (int i = 0; i<=20; i++)graph[i][i]=0;
        while(n--)
        {
            scanf("%d", &b);
            graph[a-1][b-1]=graph[b-1][a-1] = 1;
        }

        for (int a = 1; a<19; a++)
        {
            scanf("%d", &n);
            while(n--)
            {
                scanf("%d", &b);
                graph[a][b-1]=graph[b-1][a] = 1;
            }
        }
        for (int k = 0; k<20; k++)
            for (int i = 0; i<20; i++)
                for (int j = 0; j<20; j++)
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
        printf("Test Set #%d\n",cas++);
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d %d", &a, &b);
            printf("%2d to %2d: %d\n",a,b,graph[a-1][b-1]);
        }
        puts("");
    }
    return 0;
}
