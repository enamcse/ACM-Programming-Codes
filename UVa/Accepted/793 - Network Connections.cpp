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

#define sz 100000
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

int suc, unsuc;
int connection[sz];


int find_par(int x)
{
    if(connection[x]==x) return x;
    return connection[x] = find_par(connection[x]);
}

void make_rela(int x, int y)
{
    int par_x = find_par(x);
    int par_y = find_par(y);
    if(par_x==par_y) return;
    else connection[par_y] = par_x;
    return;
}

void check_rela(int x, int y)
{
    int par_x = find_par(x);
    int par_y = find_par(y);
    if(par_x==par_y) suc++;
    else unsuc++;
    return;
}

int main()
{
    int t, x, y, n;
    char c, line[sz];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        getchar();
        for (int i = 1; i<=n; i++)
            connection[i]=i;
        suc=unsuc=0;
        while(gets(line))
        {
            if(strlen(line)>1)
            {
                sscanf(line,"%c %d %d", &c, &x, &y);
                if(c=='c')make_rela(x,y);
                else check_rela(x,y);
            }
            else break;
        }
        printf("%d,%d\n", suc, unsuc);
        if(t) puts("");
    }
    return 0;
}
