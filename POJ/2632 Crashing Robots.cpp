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

#define sz 50005
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
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int grid[105][105];

int robot[105][2];

map<char,int>mpp;
map<int, char>mpr;

int main()
{
    #ifdef ENAM
    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1, a, b, x, y, dir;
    int *sx, *sy;
    char ch;
    bool crash, wall;
    mpp[ 'N' ] = 1;
    mpp[ 'S' ] = 2;
    mpp[ 'E' ] = 3;
    mpp[ 'W' ] = 4;

    mpr[ 1 ] = 'N';
    mpr[ 2 ] = 'S';
    mpr[ 3 ] = 'E';
    mpr[ 4 ] = 'W';


    scanf("%d", &t);

    while(t--)
    {
        crash = false;
        wall = false;
        clr(grid,0);
        scanf("%d %d", &a,&b);
        scanf("%d %d", &n,&m);

        for (int i = 0; i<n; i++)
        {
            scanf("%d %d %c", &x,&y, &ch);
            grid[x-1][y-1] = mpp[ ch ];
            robot[i][0] = x-1;
            robot[i][1] = y-1;
        }
        int k;
        for (k = 0; k<m; k++)
        {
            scanf("%d %c %d", &x, &ch,&y);
            x--;
            if(ch=='F')
            {
                sx = &robot[x][0];
                sy = &robot[x][1];
                dir = grid[ *sx ][ *sy ];
                while(y--)
                {
//                    cout<<ch<<": "<<*sx<<" "<<*sy<<" "<<y<<endl;
                    grid[*sx][*sy] = 0;
                    if(dir==2) {--*sy;if(*sy<0) {wall = true; break;}}
                    else if(dir==3) {++*sx;if(*sx>=a) {wall = true; break;}}
                    else if(dir==4) {--*sx;if(*sx<0) {wall = true; break;}}
                    else {++*sy;if(*sy>=b) {wall = true; break;}}
                    if(grid[*sx][*sy])
                    {
                        crash = true;
                        break;
                    }
                    grid[*sx][*sy] = dir;
//                    cout<<ch<<"::"<<*sx<<" "<<*sy<<" "<<grid[*sx][*sy]<<endl;
                }
                if(crash||wall) break;
            }
            else if(ch=='R')
            {
                sx = &robot[x][0];
                sy = &robot[x][1];
                int &now = grid[ *sx ][ *sy ];
                y%=4;
                while(y--)
                {
                    if(now==2) now = 4;
                    else if(now==3) now = 2;
                    else if(now==4) now = 1;
                    else now = 3;
                }

            }
            else if(ch=='L')
            {
                sx = &robot[x][0];
                sy = &robot[x][1];
                int &now = grid[ *sx ][ *sy ];
                y%=4;
                while(y--)
                {
                    if(now==2) now = 3;
                    else if(now==3) now = 1;
                    else if(now==4) now = 2;
                    else now = 4;
                }
            }
        }
        for (k++; k<m; k++)
        {
            scanf("%*d %*c %*d");
        }

        if(wall)
        {
            printf("Robot %d crashes into the wall\n", x+1);
        }
        else if(crash)
        {
            for (int i = 0; i<n; i++)
            {
                if(robot[i][0]==*sx&&robot[i][1]==*sy&&i!=x)
                {
                    dir=i;break;
                }
            }
            printf("Robot %d crashes into robot %d\n", x+1, dir+1);
        }
        else printf("OK\n");

    }


    return 0;
}
