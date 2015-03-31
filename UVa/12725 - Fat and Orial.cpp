/**
* H:\Dropbox\Code\UVa\12725 - Fat and Orial.cpp
* Created on: 2015-01-25-19.10.41, Sunday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <vector>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(v) v.begin(),v.end()
#define clr(y,z) memset(y,z,sizeof(y))
#define inf (1e9)
#define mod 1000000007
#define ll long long
#define pb push_back
#define SZ(a) ((int)a.size())
#define sqr(a) ((a)*(a))
#define sz 500005
#define EPS 1e-9
#define fread freopen("input.txt","r", stdin)
#define fwrite freopen("output.txt","w", stdout)

using namespace std;


int main()
{
    #ifdef ENAM
//    fread
//    fwrite
    #endif // ENAM

    int t, a, b,cas=1;
    double n, m, x,y,z;


    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf %lf %d %d",&n,&m, &a, &b);

        x = n*a;
        y = m*(a+b);
        z = y-x;
        z/=b;
        if(y>=x&&z<=10.0) printf("Case #%d: %.2lf\n",cas++, z);
        else printf("Case #%d: Impossible\n", cas++);
    }


    return 0;
}



