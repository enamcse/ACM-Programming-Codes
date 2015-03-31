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
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    int t, n, cas=1;


    scanf("%d", &t);
    while(t--)
    {
        int maxa, maxb, maxc;
        int mina, minb, minc;
        maxa = maxb = maxc = 0;
        mina = minb = minc = inf;

        scanf("%d", &n);
        for (int i = 0; i<n; i++)
        {
            int a[2],b[2],c[2];

            scanf("%d %d %d %d %d %d", &a[0], &b[0], &c[0], &a[1], &b[1], &c[1]);
            maxa = max(maxa, a[0]);
            maxb = max(maxb, b[0]);
            maxc = max(maxc, c[0]);
            mina = min(mina, a[1]);
            minb = min(minb, b[1]);
            minc = min(minc, c[1]);
        }

        if(mina-maxa>0&&minb-maxb>0&&minc-maxc>0)printf("Case %d: %d\n", cas++, (mina-maxa)*(minb-maxb)*(minc-maxc));
        else printf("Case %d: 0\n", cas++);
    }


    return 0;
}
