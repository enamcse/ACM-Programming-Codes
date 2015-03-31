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
    int t, a,b,x,y,cas=1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d", &a,&b,&x,&y);

        if(((a&1)^(b&1))^((x&1)^(y&1)))
            printf("Case %d: impossible\n",cas++);
        else
        {
            if(abs(a-x)==abs(b-y))
                printf("Case %d: 1\n",cas++);
            else printf("Case %d: 2\n",cas++);
        }
    }
    return 0;
}
