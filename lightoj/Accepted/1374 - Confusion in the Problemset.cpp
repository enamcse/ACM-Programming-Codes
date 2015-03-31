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

int page[10000];
int input[10000];


int main()
{
    int n,t,cas=1, p;
    bool flag;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        flag = true;
        for (int i = 0; i<n; i++)
            scanf("%d", &input[i]);

        for (int i =0; i<n; i++)
        {
            if(input[i]>=n)
            {
                flag = false;
                break;
            }
            p = input[i];
            if(page[p]!=cas)
            {
                page[p]= cas;
            }
            else if(page[n-p-1]!=cas) page[n-p-1]= cas;
            else
            {
                flag = false;
                break;
            }
        }
        if(flag)printf("Case %d: yes\n",cas++);
        else printf("Case %d: no\n",cas++);
    }
    return 0;
}
