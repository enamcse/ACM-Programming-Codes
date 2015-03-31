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

#define sz 100010
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


ll a[sz], b[sz];

int main()
{
    ll point = 0;
    ll t, n, x, y, cas=1;
    scanf("%I64d", &n);
    for (int i = 0; i<n; i++)
        scanf("%I64d", &a[i]);

    for (int i = 0; i<n; i++)
        scanf("%I64d", &b[i]);

    for (int i = 0; i<n; i++)
    {
        if((a[i]<<1LL)>=b[i]&&b[i]>1LL)
        {
            x = (b[i]>>1LL);
            if(b[i]%2==1) point+=(x*(x+1LL));
            else point+=(x*x);
        }
        else point--;
    }

    printf("%I64d", point);

    return 0;
}
