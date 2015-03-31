//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

#define sz 102
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

int grid[sz][sz], col[sz],n;

int kadane()
{
    int ans_max, pre_max;
    ans_max = pre_max = col[0];
    for (int i = 1; i<n; i++)
    {
        pre_max = max(col[i],col[i]+pre_max);
        ans_max = max(ans_max, pre_max);
    }
    return ans_max;
}

int main()
{
    int x,mn;
    while(~scanf("%d", &n))
    {
        mn=-inf;
        for (int i = 0; i<n; i++)
        {
            grid[i][0]=0;
            for (int j = 0; j<n; j++)
                scanf("%d", &grid[i][j+1]);
        }

        for (int i = 0; i<n; i++)
        {
            for (int j = 1; j<=n; j++)
            {
                grid[i][j]+=grid[i][j-1];
//                cout<<grid[i][j]<<" ";
            }
//            cout<<endl;
        }


        for (int i = 0; i<n; i++)
        {
            for (int j = i+1; j<=n; j++)
            {
                for (int k = 0; k<n; k++)
                {
                    col[k] = grid[k][j]-grid[k][i];
//                    cout<<col[k]<<" ";
                }
                mn = max(mn,kadane());
//                cout<<i<<" "<<j<<"::"<<mn<<endl;
            }
        }
        printf("%d\n", mn);
    }
    return 0;
}
/*
4
0 -2 -7  0
9  2 -6  2
-4  1 -4  1
-1 8  0 -2
*/
























//everybody needs header to write a code, but I also need footer! :)
