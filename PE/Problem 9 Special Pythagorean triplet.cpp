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
    for (int a=1; a<1000; a++)
        for (int b = a; b<1000; b++)
            for (int c = b; c<1000; c++)
                if(a+b+c==1000&&(a*a+b*b==c*c)) cout<<a*b*c<<endl;
    return 0;
}
