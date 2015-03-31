#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <string.h>

using namespace std;

#define clr(y,z) memset(y,z, sizeof(y))
#define cntbit(mask) _builtin_popcount(mask)
#define fs first
#define sc second
#define pb push_back
#define pp pop_back
#define chg(a, b) a^=b^=a^=b
#define sz 1005
#define inf (1e9)

int arr[sz];

int main()
{
    #ifdef ENAM
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif

    int n,cnt;

    while(scanf("%d", &n))
    {
        cnt=0;
        clr(arr,0);
        if(n==-1) break;
        scanf("%d", &arr[0]);
        if(arr[0]%100==0) cnt++;
        for (int i = 1; i<n; i++)
        {
            scanf("%d", &arr[i]);
            arr[i]+=arr[i-1];
            if(arr[i]%100==0) cnt++;
        }




        printf("%d\n", cnt);
    }

    return 0;
}
