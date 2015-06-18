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
using namespace std;


int main()
{
    int n, k,l,r,cnt=0;
    bool flag=true;
    scanf("%d %d", &n, &k);
    l=1,r=n;
    while(k)
    {
        if(flag)
        {
            printf("%d", l);
            flag = false;
            l++;
            cnt++;
            if(cnt!=n) printf(" ");
        }
        else
        {
            printf("%d", r);
            flag = true;
            r--;cnt++;
            if(cnt!=n) printf(" ");
        }
        k--;
    }
    if(flag)
    {
        for (int i = r; i>=l; i--)
        {
            printf("%d", i);cnt++;
            if(cnt!=n) printf(" ");
        }

    }
    else
    {
        for (int i = l; i<=r; i++)
        {
            printf("%d", i);cnt++;
            if(cnt!=n) printf(" ");
        }

    }

    return 0;
}
