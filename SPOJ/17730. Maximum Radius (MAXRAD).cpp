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

#define sz 100
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

int x[1000], y[1000];

int main()
{
    int t, n;
    scanf("%d", &t);
    double a, b, c, d;
    while(t--)
    {
        c=0;
        scanf("%d", &n);
        for (int i = 0; i<n; i++)
            scanf("%d %d", &x[i], &y[i]);

        for (int i = 0; i<n; i++)
        {
            d = 1e9;
            for (int j = 0; j<n; j++)
            {
                if(i==j) continue;
                a = (x[i]-x[j]);
                b = (y[i]-y[j]);
                d = min(sqrt(a*a+b*b),d);
            }
            c = max(d,c);
        }

            if(c<2)
            {
                printf("%.6lf\n",-1.0);
            }
            else printf("%.6lf\n",c-1.0);
    }
	return 0;
}
