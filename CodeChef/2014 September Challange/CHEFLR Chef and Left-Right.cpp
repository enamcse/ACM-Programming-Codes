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
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define mod 1000000007
using namespace std;

char line[sz];


int main()
{
    int n, t;
    ll now=1ll;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%s", line);
        n = strlen(line);
        now=1ll;
        for (int i = 0; i<n; i++)
        {
            now<<=1ll;
            if(i%2)
            {
                if(line[i]=='r') now++;
                else now--;
            }
            else if(line[i]=='r') now+=2;
            now%=mod;
        }
        printf("%lld\n", now);
    }

    return 0;
}
