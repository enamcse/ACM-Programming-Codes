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

int a[50], b[50];
int col_a[50],col_b[50];
int main()
{
    int n, cas=1,t, mx, ind, point;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        point = 0;
        for (int i =0; i<n; i++)
            scanf("%d", &a[i]);
        for (int i =0; i<n; i++)
            scanf("%d", &b[i]);
        sort(a,a+n);
        reverse(a,a+n);
        for (int i =0; i<n; i++)
        {
            ind = mx = -1;
            for (int j = 0; j<n; j++)
                if(a[i]>b[j] and b[j]>mx and col_b[j]!=cas)
                {
                    mx = b[j];
                    ind = j;
                }
            if(ind!=-1) point+=2;
            for (int j = 0; j<n; j++)
                if(a[i]==b[j] and col_b[j]!=cas)
                {
                    col_b[j] = cas;
                    if(ind!=-1) point--;
                    else point++;
                    ind = j;
                    break;
                }
            col_a[i] = cas;
            col_b[ind] = cas;

        }
        printf("Case %d: %d\n", cas++, point);
    }
    return 0;
}
