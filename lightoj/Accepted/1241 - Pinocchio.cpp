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
using namespace std;

int main()
{
    int t, n,a,pre, cnt,cas=1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        scanf("%d", &pre);
        if(pre>2)cnt=ceil((pre-2)/5.0);
        else cnt = 0;
        while(--n)
        {
            scanf("%d", &a);
            cnt+=ceil((a-pre)/5.0);
            pre = a;
        }
        printf("Case %d: %d\n", cas++,cnt);
    }
    return 0;
}
