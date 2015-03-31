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
#define mod 100000007
using namespace std;

vector<int>b(1000);

int a[1000], dp[1024][1024],n;

int rec(int now, int pos)
{
    if(pos==n)
        if(binary_search(b.begin(),b.end(),now)) return 0;
        else return 1;
    if(dp[now][pos]!=-1) return dp[now][pos];
    int &ret = dp[now][pos];
    ret = (rec((now^a[pos]), pos+1)%mod + rec(now, pos+1)%mod)%mod;
    return ret;
}

int main()
{
    int t, cas=1, num,m;
    scanf("%d", &t);
    while(t--)
    {
        b.clear();
        clr(dp,-1);
        scanf("%d %d", &n, &m);
        for (int i = 0; i<n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i<m; i++)
        {
            scanf("%d", &num);
            b.pb(num);
        }
        sort(b.begin(),b.end());
        printf("Case %d: %d\n",cas++,rec(0,0));
    }
    return 0;
}
