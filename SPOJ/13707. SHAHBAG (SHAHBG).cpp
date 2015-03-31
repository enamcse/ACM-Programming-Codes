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
#define sz 20001
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

bool flag[sz];

int main()
{
    int n, a, cnt=0;
    bool x, y;
    scanf("%d", &n);
    clr(flag,false);
    while(n--)
    {
        scanf("%d", &a);
        flag[a]=true;
        if(flag[a-1]&&flag[a+1])
        {
            cnt--;
        }
        else if(flag[a-1]||flag[a+1]) ;
        else cnt++;
        printf("%d\n", cnt);
    }
    printf("Justice\n");
    return 0;
}
