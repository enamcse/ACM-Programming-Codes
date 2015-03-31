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
using namespace std;

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int a = -(1<<31); // a = 1<<(8*sizeof(a)-1);
    long long x,z;
    double y ;
    x = 9223372036854775800LL;
    y = 9223372036854775800LL;
    z = 9223372036854775807LL;
    cout<<(a==-a)<<" "<<(a!=0)<<endl;
    cout<<x<<" "<<y<<" "<<z<<endl;
    cout<<(x==y)<<" "<<(y==z)<<" "<<(x==z)<<endl;
    printf("%lld %20lf %lld\n",x,y,z);
    printf("%lld %lld %lld\n",x,(ll)y,z);
    for (double r=0.0; r!=1.0; r+=0.1) printf("*");
    return 0;
}
