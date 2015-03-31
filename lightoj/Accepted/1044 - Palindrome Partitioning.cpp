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

#define sz 1005
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
char line[1005];

short com[sz][sz];
int dp[sz][sz];

short rec(int a, int b)
{
    if(a>=b) return 1;
    short &ret = com[a][b];
    if(ret!=-1) return ret;
    return ret = line[a]==line[b] & rec(a+1,b-1);
}

int find_ans(int a, int b)
{
    int &ret = dp[a][b];
    if(ret!=-1) return ret;
    ret=inf;
    for (int i = a; i<=b; i++)
        if(rec(i,b)) ret = min(ret, find_ans(a,i-1)+1);
    return ret;
}

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1;

    scanf("%d", &t);

    while(t--)
    {
        clr(dp,-1);
        clr(com,-1);
        scanf("%s", line);

        printf("Case %d: %d\n", cas++, find_ans(0,strlen(line)-1));

    }
    return 0;
}
