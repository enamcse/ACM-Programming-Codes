#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
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
    ll num, fib1=0, fib2=1, sum =0, fib;

    while(1)
    {
        fib = fib1+fib2;
        if(fib>4000000) break;
        if(!(fib%2)) sum+=fib;
        fib1= fib2;
        fib2=fib;
    }
    cout<<sum<<endl;
    return 0;
}
