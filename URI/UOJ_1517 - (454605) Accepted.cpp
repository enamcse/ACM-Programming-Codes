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

#define sz 2005
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

int xx[] = {0,  0, -1, 1, 1,  1, -1, -1};
int yy[] = {1, -1,  0, 0, 1, -1,  1, -1};

using namespace std;

int dp[21][21][sz],K, apple[21][21][sz], n, m;


int rec(int x, int y, int t)
{
    if(t == K+1) return 0;
    int &ret = dp[x][y][t];

    if(ret!= -1) return ret;

    int a, b;
    ret = 0;

    for (int i = 0; i<8; i++)
    {
        a = x+xx[i];
        b = y+yy[i];
        if(a<1||b<1||a>n||b>m) continue;
        ret = max(ret, rec(a,b,t+1)+apple[a][b][t+1]);
    }
    ret = max(ret, rec(x,y,t+1)+apple[x][y][t+1]);
    return ret;
}


int main()
{
    int t, cas=1,x,y,k;

    while(~scanf("%d %d %d", &n, &m, &k)&&(n||m||k))
    {
        clr(dp,-1);
        clr(apple,0);
        for (int i = 1; i<=k; i++)
        {
            scanf("%d %d %d", &x, &y, &t);
            apple[x][y][t]=1;
        }
        K=t;
        scanf("%d %d", &x, &y);

        printf("%d\n",rec(x,y,0));

    }



    return 0;
}
