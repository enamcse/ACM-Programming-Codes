/*
ID: manetsus
PROG: ride
LANG: C++
*/
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
#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    char a[10], b[10];
    int x=1,y=1, len, n;
    fin>>a>>b;
    len = strlen(a);

    for (int i = 0; i<len; i++)
    {
        n = a[i] - 'A' + 1;
        x*= n;
    }

    len = strlen(b);

    for (int i = 0; i<len; i++)
    {
        n = b[i] - 'A' + 1;
        y*= n;
    }

    x%= 47;
    y%= 47;

    if(x==y) fout<<"GO"<<endl;
    else fout<<"STAY"<<endl;

    return 0;
}
