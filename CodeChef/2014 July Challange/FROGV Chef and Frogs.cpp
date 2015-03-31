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

#define sz 100005
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

int k;
int cnt=0;

struct data{
    int val;
    int pos;
};

data arr[sz];
int ans[sz];

bool compValue(const data &a, const data &b)
{
    return a.val<b.val;
}

int main()
{
//    #ifdef ENAM
//    	fread;
//	fwrite;
//    #endif // ENAM
    int n, p, cas=1, x, y;

    scanf("%d %d %d", &n, &k, &p);

    for (int i = 1; i<=n; i++)
    {
        arr[i].pos = i;
        scanf("%d", &arr[i].val);
    }

    sort(arr+1, arr+n+1, compValue);
    ans[1] = cnt;

    for (int i = 2; i<=n; i++)
    {
        if(arr[i].val-arr[i-1].val<=k) ans[ arr[i].pos ] = cnt;
        else ans[ arr[i].pos ] = ++cnt;
    }
    for (int i = 0; i<p; i++)
    {
        scanf("%d %d", &x, &y);
        if(ans[x]==ans[y]) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
