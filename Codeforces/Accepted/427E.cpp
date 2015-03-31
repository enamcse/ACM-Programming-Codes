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

#define sz 1000055
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

int n, m;

vector<int>v;

double calc_dist(int now)
{
    ll time=0;
    int cnt=0;

    for (int i = 0; v[i]<v[now]; i++)
    {
        if(cnt==0) time+=(abs(v[now]-v[i]));
        cnt++;
        if(cnt==m) cnt = 0;
    }

    cnt=0;
    for (int i = n - 1; v[i]>v[now]; i--)
    {
        if(cnt==0) time+=(abs(v[now]-v[i]));
        cnt++;
        if(cnt==m) cnt = 0;
    }
    return 2*time;
}


int main()
{
    #ifdef ENAM
    	fread;
	fwrite;
    #endif // ENAM
    int l=0, m1,m2, r;
    int k;
    ll ans = (1LL<<62);
    scanf("%d %d", &n, &m);

    for (int i = 0; i<n; i++)
    {
        scanf("%d", &k);
        v.pb(k);
    }
    r = n-1;

    m1 = (r+2*l)/3.0;
    m2 = (2*r+l)/3.0;

    while(abs(l-r)>3)
    {
        if(calc_dist(m1)<calc_dist(m2)) r = m2;
        else l = m1;
        m1 = (r+2*l)/3.0;
        m2 = (2*r+l)/3.0;
    }

    for (ll i= max(l-2,0); i<=min(r+2,n-1); i++)
        ans = min(ans,(ll)calc_dist(i));

    printf("%lld", ans);


    return 0;
}
