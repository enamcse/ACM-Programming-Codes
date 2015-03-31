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

char input[sz][sz], line[100*sz];
string s, ss;

int main()
{
    int t, n, m, cas=1, a, b, x, y;
    while(~scanf("%d %d", &n, &m)&&(n||m))
    {
        getchar();
        for (int i = 0; i<n; i++) gets(input[i]);
        scanf("%d %d", &a, &b);
        x = a/n;
        y = b/m;

        for (int i = 0; i<n; i++)
        {
            t = strlen(input[i]);
            ss = "";
            for (int k = 0; k<t; k++)
            {
                s =input[i][k];

                for (int j = 0; j<y; j++)
                    ss+=s;
            }

            for (int j = 0; j<x; j++)
                printf("%s\n", ss.c_str());
        }
        puts("");
    }
    return 0;
}
