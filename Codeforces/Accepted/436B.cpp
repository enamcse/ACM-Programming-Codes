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

#define sz 2005
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

int n, m, k;
char line[sz][sz];

int col[sz];

void func(int i, int j, char c)
{
    if(c == 'L')
    {
        int a = j - i;
        if(a>=0) col[a]++;
    }
    else if(c == 'R')
    {
        int a = j + i;
        if(a<m) col[a]++;
    }
    else if(c == 'U' && i%2==0) col[j]++;
    return;
}


int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int cc, cr;

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i<n; i++)
        scanf("%s", line[i]);

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<m; j++)
        {
            func(i,j,line[i][j]);
        }
    }

    for (int i = 0; i<m; i++)
        printf("%d ", col[i]);


    return 0;
}
