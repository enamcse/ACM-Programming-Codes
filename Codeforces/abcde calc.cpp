//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define all(a,b,c)      for(int I=0;I<b;I++)    a[I] = c
#define BE(a)           a.begin(),a.end()
#define chng(a,b)       a^=b^=a^=b;
#define clr(y,z)        memset(y,z,sizeof(y))
#define cntbit(mask)     __builtin_popcount(mask)
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define EQ(a,b)         (fabs(a-b)<ERR)
#define ERR             1e-5
#define FORE(i,a)       for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define fr(i,a,b)       for(i=a;i<=b;i++)
#define fread           freopen("input.txt","r",stdin)
#define fri(a,b)        for(int i=a;i<=b;i++)
#define frj(a,b)        for(int j=a;j<=b;j++)
#define frk(a,b)        for(int k=a;k<=b;k++)
#define frl(a,b)        for(int l=a;l<=b;l++)
#define frin(a,b)       for(int i=a;i>=b;i--)
#define frjn(a,b)       for(int j=a;j>=b;j--)
#define frkn(a,b)       for(int k=a;k>=b;k--)
#define frln(a,b)       for(int l=a;l>=b;l--)
#define frn(i,a,b)      for(i=a;i>=b;i--)
#define fwrite          freopen("output.txt","w",stdout)
#define inf             (1e9)
#define inpow(a,x,y)    int i; a=x;fri(2,y)  a*=x
#define makeint(n,s)    istringstream(s)>>n
#define mod             1000000007
#define ISS             istringstream
#define ll              long long
#define oo              (1<<30)
#define OSS             ostringstream
#define pb              push_back
#define PI              3.141592653589793
#define pi              (2*acos(0))
#define pp              pop_back
#define PRE             1e-8
#define print1(a)       cout<<a<<endl
#define print2(a,b)     cout<<a<<" "<<b<<endl
#define print3(a,b,c)   cout<<a<<" "<<b<<" "<<c<<endl
#define rev(a)          reverse(BE(a));
#define round(i,a)      i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define SI              set<int>
#define SII             set<int>::iterator
#define SIZE(s)         ((int)s.size())
#define saja(a)        sort(BE(a))
#define sqr(a)          ((a)*(a))
#define SZ              50005
#define SZ1             55
#define typing(j,b)     typeof((b).begin()) j=(b).begin();
#define VD              vector<double>
#define VI              vector<int>
#define VLL             vector<long long>
#define VS              vector<string>

int number[10];

int main()
{
    int t, n, m, cas=0;

    FILE *file = fopen("AC_list_in_site.txt", "r");
    char line[100];

    while(!feof(file))
    {
        fscanf(file,"%s",line);
        n = (int)(line[(strlen(line)-1)]-'a');
        if(n<=4)
        {
            number[n]++;
        }
        else number[5]++;
        cas++;
    }
    fclose(file);
    printf("     A =%5d\n", number[0]);
    printf("     B =%5d\n", number[1]);
    printf("     C =%5d\n", number[2]);
    printf("     D =%5d\n", number[3]);
    printf("     E =%5d\n", number[4]);
    printf("Others =%5d\n", number[5]);
    puts("-------------");
    printf("Total  =%5d\n",cas);

    return 0;
}
