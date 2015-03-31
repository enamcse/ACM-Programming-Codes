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
#include<set>

#define sz 50
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

ll fib[sz];

int main()
{
    ll n, ans;
    fib[0]=0;
    fib[1]=1;
    bool flag = true;
    for (int i =2; i<sz; i++)
        fib[i]=fib[i-1]+fib[i-2];
    scanf("%lld", &n);
    for (int i = 0; i<sz&&flag; i++)
        for (int j = 0; j<sz&&flag; j++)
            for (int k = 0; k<sz&&flag; k++)
            {
                if(fib[i]+fib[j]+fib[k]==n)
                {
                    printf("%lld %lld %lld\n", fib[i], fib[j], fib[k]);
                    flag=false;
                    break;
                }
            }
    return 0;
}
