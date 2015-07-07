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


char grid[9][10], ans[9][10];
int limit=9,up;

int sq[9];
int column[9], row[9];
bool flag;
int quad[9][9];

struct point{
    int x, y;
};

vector<point>v;

void rec(int z)
{
    if(!flag) return;
    if(z==up)
    {
        flag = false;

        for (int i = 0; i<limit; i++)
            strcpy(ans[i],grid[i]);

        return;
    }

    int a=0, b, c=inf;
    point p;
    for (int i = 0; i<up; i++)
    {
        p = v[i];

        if(grid[p.x][p.y]!='.') continue;
        b=0;

        for (int j = 1; j<=limit; j++)
            if(!(sq[ quad[p.x][p.y] ]&(1<<j)) && !(column[p.y]&(1<<j)) && !(row[p.x]&(1<<j)) ) b++;
        if(b<c)
        {
            c = b;
            a = i;
        }
    }
    if(c==0) return;
    p = v[a];

    for (int j = 1; j<=limit; j++)
    {
        if(!(sq[ quad[p.x][p.y] ]&(1<<j)) && !(column[p.y]&(1<<j)) && !(row[p.x]&(1<<j)) )
        {
            sq[ quad[p.x][p.y] ]|=(1<<j);
            column[p.y]|=(1<<j);
            row[p.x]|=(1<<j);
            grid[p.x][p.y] = j+'0';
            if(flag) rec(z+1);
            sq[ quad[p.x][p.y] ]^=(1<<j);
            column[p.y]^=(1<<j);
            row[p.x]^=(1<<j);
            grid[p.x][p.y] = '.';
        }
    }

    return;
}


int main()
{
    int t, n=3, m, cas=1,len, cnt;
//    vector<int>q;
    scanf("%d", &t);
    getchar();
    point p;
    for (int i = 0; i<limit; i++)
            for (int j = 0; j<limit; j++)
                quad[i][j] = (i/n)*n+(j/n);

    while(t--)
    {
        gets(grid[0]);
        clr(column,0);
        clr(row,0);
        clr(sq,0);
        v.clear();
        flag = true;
        for (int i = 0; i<limit; i++)
        {
            gets(grid[i]);
            for (int j = 0; j<limit; j++)
            {

                if(grid[i][j]!='.')
                {
                    m = grid[i][j] - '0';
                    sq[ quad[i][j] ]|= (1<<m);
                    column[j]|= (1<<m);
                    row[i]|= (1<<m);
                }
                else
                {
                    p.x = i;
                    p.y = j;
                    v.pb(p);
                }
            }
        }

        up = v.size();
        rec(0);
        printf("Case %d:\n",cas++);
        for (int i = 0; i<limit; i++)
            printf("%s\n", ans[i]);

    }


    return 0;
}
/*
1

.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
*/
