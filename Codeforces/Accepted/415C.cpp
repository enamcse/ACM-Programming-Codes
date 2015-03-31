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

#define sz 55
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

int main()
{
    int t, n, m, cas=1, p, q, cnt=1, a,b;

    scanf("%d %d", &n, &m);

    p = (n>>1);
    if(p>m)
    {
        printf("-1");
        return 0;
    }

    a = m - (p-1);
    b = (a<<1);
    if(n!=1) printf("%d %d", a, b);
    else
    {
        if(m)printf("%d", -1);
        else printf("%d", 1);
    }

    for (int i = 2; i<n; i++, cnt+=2)
    {
        if(a==cnt) printf(" %d", 999999937);
        else printf(" %d", cnt);
    }


    return 0;
}
