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
#define mod 1000000007
using namespace std;

ll mult[100000], num[100000];

void calc(int n)
{
    int now = n-1;
    for (int i = 0; i<n; i++,now-=2)
        mult[i]=now;
    return;
}


int main()
{
    int t, n, v, x, q, y, cas=1;
    ll sum;
    scanf("%d", &t);
    while(t--)
    {
        printf("Case %d:\n", cas++);
        sum=0;
        scanf("%d %d", &n, &q);
        for (int i = 0; i<n; i++)
            scanf("%lld", &num[i]);
        calc(n);
        for (int i = 0; i<n; i++)
            sum+= (mult[i]*num[i]);
        while(q--)
        {
            scanf("%d", &y);
            if(y==0)
            {
                scanf("%d %d", &x, &v);
                sum-=(mult[x]*num[x]);
                num[x] = v;
                sum+=(mult[x]*num[x]);
            }
            else
                printf("%lld\n",sum);
        }
    }
	return 0;
}
