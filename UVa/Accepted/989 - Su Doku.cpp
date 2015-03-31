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

#define sz 55
#define pb(a) push_back(a)
#define pp pop_back()
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


int grid[9][9], limit,up;

int sq[9];
int column[9], row[9];
bool flag;
int quad[9][9];

void rec(int p, int q)
{

    q++;
    if(q==limit) q=0,p++;
    if(p == limit)
    {
        flag =true;
        for (int i = 0; i<limit; i++)
        {
            for (int j = 0; j<limit; j++)
            {
                printf("%d", grid[i][j]);
                if(j!=limit-1) printf(" ");
            }
            puts("");
        }
        return;
    }
    if(grid[p][q])
    {
        rec(p,q);
        return;
    }

    for (int i = 1; i<=limit; i++)
    {
        if(!(sq[ quad[p][q] ]&(1<<i)) && !(column[q]&(1<<i)) && !(row[p]&(1<<i)) )
        {
            sq[ quad[p][q] ]|=(1<<i);
            column[q]|=(1<<i);
            row[p]|=(1<<i);
            grid[p][q] = i;
            rec(p,q);
            sq[ quad[p][q] ]^=(1<<i);
            column[q]^=(1<<i);
            row[p]^=(1<<i);
            grid[p][q] = 0;
        }
        if(flag) break;
    }

    return;
}

int main()
{
    int t, n, m, cas=0,len, p , q;
    while(~scanf("%d", &n))
    {
        if(cas++) puts("");
        flag = false;
        clr(column,0);
        clr(row,0);
        clr(sq,0);
        limit = n*n;
        for (int i = 0; i<limit; i++)
            for (int j = 0; j<limit; j++)
                quad[i][j] = (i/n)*n+(j/n);


        for (int i = 0; i<limit; i++)
            for (int j = 0; j<limit; j++)
            {
                scanf("%d", &grid[i][j]);
                if(grid[i][j])
                {
                    sq[ quad[i][j] ]|= (1<<grid[i][j]);
                    column[j]|= (1<<grid[i][j]);
                    row[i]|= (1<<grid[i][j]);
                }
            }

        p=q=-1;
        for (int i = 0; i<limit; i++)
        {
            for (int j = 0; j<limit; j++)
            {
                if(grid[i][j]==0)
                {
                    p = i;
                    q = j;
                    break;
                }
            }
            if(p>=0) break;
        }

        for (int i = 1; i<=limit; i++)
        {
            if(!(sq[ quad[p][q] ]&(1<<i)) && !(column[q]&(1<<i)) && !(row[p]&(1<<i)) )
            {
                sq[ quad[p][q] ]|=(1<<i);
                column[q]|=(1<<i);
                row[p]|=(1<<i);
                grid[p][q] = i;

                rec(p,q);

                sq[ quad[p][q] ]^=(1<<i);
                column[q]^=(1<<i);
                row[p]^=(1<<i);

                grid[p][q] = 0;
            }
            if(flag) break;
        }

        if(!flag)
        {
            printf("NO SOLUTION\n");
        }
    }


    return 0;
}
