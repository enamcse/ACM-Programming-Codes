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
#define sz 100005
#define inf (1e9)

struct data{
    char line[200];
    char original[200];
    int cost;
    int i;
};

bool comp(const data &a, const data &b)
{
    if(a.cost==b.cost) return a.i==b.i;
    return a.cost<b.cost;
}

int main()
{
    #ifdef ENAM
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif

    int n, m, k;

    data arr[200];
    char temp;

    scanf("%d %d", &n, &m);

    for (int i = 0; i<m; i++)
    {
        scanf("%s", arr[i].line);
        strcpy(arr[i].original,arr[i].line);
        arr[i].cost = 0;
        arr[i].i = i;
        for (int j = 1; j<n; j++)
        {
            if(arr[i].line[j]<arr[i].line[j-1])
            {
                k = j-1;
                while(k>=0)
                {
                    temp = arr[i].line[k];
                    arr[i].line[k] = arr[i].line[k+1];
                    arr[i].line[k+1] = temp;
                    arr[i].cost++;
                    if(k==0) break;
                    if(arr[i].line[k]>=arr[i].line[k-1])
                    {
                        break;
                    }
                    k--;
                }
            }
        }
    }

    sort(arr, arr+m, comp);

    for (int i = 0; i<m; i++)
    	printf("%s\n", arr[i].original);







    return 0;
}
