#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#define sz 20
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

int grid[sz][sz];

int main()
{
    int mx, prod;

    for (int i = 0; i<sz; i++)
        for (int j=0; j<sz; j++)
            cin>>grid[i][j];
    //up-down
    for (int i = 0; i<sz-3; i++)
        for (int j = 0; j<sz; j++)
        {
            prod = grid[i][j];
            for (int k = 1; k<=3; k++)
                prod*=grid[i+k][j];
            mx = mx>prod?mx:prod;
        }

    //left-right
    for (int i = 0; i<sz; i++)
        for (int j = 0; j<sz-3; j++)
        {
            prod = grid[i][j];
            for (int k = 1; k<=3; k++)
                prod*=grid[i][j+k];
            mx = mx>prod?mx:prod;
        }

        //diagonal left to right
        for (int i = 0; i<sz-3; i++)
        for (int j = 0; j<sz-3; j++)
        {
            prod = grid[i][j];
            for (int k = 1; k<=3; k++)
                prod*=grid[i+k][j+k];
            mx = mx>prod?mx:prod;
        }

        //diagonal left to right
        for (int i = 0; i<sz-3; i++)
        for (int j = 3; j<sz; j++)
        {
            prod = grid[i][j];
            for (int k = 1; k<=3; k++)
                prod*=grid[i+k][j-k];
            mx = mx>prod?mx:prod;
        }

        cout<<mx<<endl;
    return 0;
}
