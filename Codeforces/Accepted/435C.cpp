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

#define sz 2500
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


char grid[sz][1000];

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m,  cas=1, up=sz/2, down=sz/2, y=sz/2,x=0;

    scanf("%d", &t);

    for (int i = 0; i<sz; i++)
        for (int j = 0; j<1000; j++)
            grid[i][j]=' ';

    for (int i = 0; i<t; i++)
    {
        scanf("%d", &m);

        if(i%2==0)
        {
            while(m>0){
                grid[y--][x++] ='/';
                m--;
            }
            y++;
            up=min(up,y);
            down = max(down,y);
        }
        else
        {
            while(m>0){
                grid[y++][x++] ='\\';
                m--;
            }
            y--;
            up=min(up,y);
            down = max(down,y);
        }
    }

    for (int i = up; i<=down; i++)
        {
            for (int j = 0; j<x; j++)
                printf("%c", grid[i][j]);
            puts("");
        }
    return 0;
}
