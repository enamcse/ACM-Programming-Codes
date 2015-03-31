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

struct res
{
    int p, q;
    res() {}
    res(int s, int t)
    {
        p = s;
        q = t;
    }
};

vector<res>a,b, ans;

bool comp(res const &x, res const &y)
{
    return x.q<y.q;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int n, m, i, k, mov=0;
    scanf("%d", &n);
    m = n/2;
    for (i = 0; i<m; i++)
    {
        scanf("%d", &k);
        a.pb(res(i,k));
    }

    for (; i<n; i++)
    {
        scanf("%d", &k);
        b.pb(res(i,k));
    }

    sort(a.begin(),a.end(), comp);
    sort(b.rbegin(),b.rend(), comp);

    for (int j = 0; j<m; j++)
    {
        mov += n - j - 1;
        if(a[j].q<b[0].q||mov>2*n) break;
        ans.pb(res(j+1,n));
    }
    m = ans.size();
    printf("%d\n", m);

    for (i = 0; i<m; i++)
        printf("%d %d\n", ans[i].p, ans[i].q);
    return 0;
}
