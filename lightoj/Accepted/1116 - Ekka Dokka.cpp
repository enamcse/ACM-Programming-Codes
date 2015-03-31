#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include<set>
#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int main()
{
    ll t, n, w,cas=1, m;
    scanf("%lld", &t);

    while(t--)
    {
        scanf("%lld", &w);
        m = 1;
        if(w%2) printf("Case %lld: Impossible\n",cas++);
        else
        {
            while(!(w%2))
            {
                m<<=1;
                w>>=1;
            }
            n = w;
            printf("Case %lld: %lld %lld\n",cas++, n, m);
        }
    }

    return 0;
}
