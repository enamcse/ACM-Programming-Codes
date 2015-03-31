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
    int n,len,t, caseno=1;
    char line[sz];
    bool flag;
    scanf("%d ", &n);
    while(n--)
    {
        flag = true;
        gets(line);
        len = strlen(line);
        t =(len>>1);
        for (int i = 0; i<t; i++)
        {
            if(line[i]!=line[len-1-i])
            {
                flag = false;
                break;
            }
        }
        if(flag) printf("Case %d: Yes\n", caseno++);
        else printf("Case %d: No\n", caseno++);
    }
}
