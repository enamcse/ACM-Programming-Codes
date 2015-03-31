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
#include <string>
#include <stack>
#include <bitset>

#define sz 105
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

bool last[sz];

int adj[sz][sz];
int dp[sz][10*sz];
int c,s,e,t, m;


int rec(int node, int rem)
{
    if(rem==0) return 0;
    int &ret = dp[node][rem];
    if(ret!=-1) return ret;

    if(rem==1)
    {
        for (int i = 0; i<c; i++)
            if(last[i]) ret = max(ret, adj[node][i]);
        return ret;
    }

    for (int i = 0; i<c; i++)
        ret = max(ret, adj[node][i] + rec(i, rem-1));
    return ret;
}


int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM


    while(~scanf("%d %d %d %d", &c, &s, &e, &t)&&c&&s&&e&&t)
    {
        clr(last, false);
        clr(dp, -1);
        for (int i = 0; i<c; i++)
            for (int j = 0; j<c; j++)
                scanf("%d", &adj[i][j]);

        for (int i = 0; i<e; i++)
        {
            scanf("%d", &m);
            last[m-1] = true;
        }
        printf("%d\n", rec(s-1,t) );
    }



    return 0;
}
