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
    int a[4],b[4],c[4], caseno=1, n;
    bool flag;
    scanf("%d", &n);

    while(n--)
    {
        scanf("%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
        scanf("%d.%d.%d.%d", &b[0], &b[1], &b[2], &b[3]);
        c[0] = c[1] = c[2] = c[3] = 0;
        flag = true;
        for (int i = 0; i<8; i++)
        {
            for (int j = 0; j<4; j++)
            {
                c[j]+=((b[j] & 1)<<i);
                b[j]/=10;
            }
        }
//        cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
//        cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<endl;
        for (int j = 0; j<4; j++)
                if(c[j]!=a[j]) flag = false;
        if(flag) printf("Case %d: Yes\n", caseno++);
        else printf("Case %d: No\n", caseno++);
    }

    return 0;
}
