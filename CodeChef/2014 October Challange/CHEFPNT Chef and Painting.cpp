//Verdict: NOT SOLVED
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
#include <string>
#include <stack>
#include <bitset>

#define sz 100005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

bool grid[105][105];

vector< pair<int, int> > col, row;

int main()
{
#ifdef ENAM
//        fread;
//    fwrite;
#endif // ENAM
    int t, n, m, k, x, y, temp;

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i<k; i++)
    {
        scanf("%d %d", &x, &y);
        grid[x-1][y-1] = true;
    }

    for (int i = 0; i<n; i++)
    {
        temp=0;
        for (int j = 0; j<m; j++)
            if(grid[i][j])
            {
                if(temp)
                {
                    row.pb(make_pair(i+1,j));
                    temp=0;
                }
            }
            else temp++;
        if(temp) row.pb(make_pair(i+1,n));
    }

    for (int i = 0; i<m; i++)
    {
        temp=0;
        for (int j = 0; j<n; j++)
            if(grid[j][i])
            {
                if(temp)
                {
                    col.pb(make_pair(j,i+1));
                    temp=0;
                }
            }
            else temp++;
        if(temp) col.pb(make_pair(n,i+1));
    }

    x = row.size();
    y = col.size();

    if(x<y)
    {
        printf("%d\n", x);
        for (int i = 0; i<x; i++)
            printf("%d %d 0\n", row[i].first, row[i].second);
    }
    else
    {
        printf("%d\n", y);
        for (int i = 0; i<y; i++)
            printf("%d %d 1\n", col[i].first, col[i].second);
    }


        return 0;
}

