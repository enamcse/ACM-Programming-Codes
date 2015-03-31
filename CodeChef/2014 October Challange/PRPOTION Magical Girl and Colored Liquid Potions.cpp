//Verdict: NOT SOLVED
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
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9+10)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007

using namespace std;

vector<int>v,r,g,b;

int main()
{
#ifdef ENAM
//        fread;
//    fwrite;
#endif // ENAM
    int m,a,d,c,n,mn,t;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d %d %d", &a, &d, &c, &m);
        r.clear();
        g.clear();
        b.clear();
        v.clear();
        for (int i = 0; i<a; i++)
        {
            scanf("%d", &n);
            r.pb(n);
        }
        for (int i = 0; i<d; i++)
        {
            scanf("%d", &n);
            g.pb(n);
        }
        for (int i = 0; i<c; i++)
        {
            scanf("%d", &n);
            b.pb(n);
        }

        sort(rall(r));
        sort(rall(g));
        sort(rall(b));

        v.pb(r[0]);
        v.pb(g[0]);
        v.pb(b[0]);
        sort(rall(v));

        mn = v[0];

        int mx;
        for (int i = 0; i<m; i++)
        {
            v[0]>>=1;
//            v[1]++;
//            v[2]++;
            sort(rall(v));
            mn = min(mn,v[0]);
        }
        printf("%d\n", mn);
    }
    return 0;
}

