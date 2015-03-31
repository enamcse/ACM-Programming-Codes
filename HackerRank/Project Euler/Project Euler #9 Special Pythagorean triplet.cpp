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

ll mem[3005];

int func(int n)
{
    if(mem[n]!=-5LL) return mem[n];
    ll &ret = mem[n];
    ret=-1LL;
    for (int a=1; a<3001; a++)
    {
        if(a>=n) break;
        for (int b = a; b<3001; b++)
        {
            ll c = n - a - b;
            if(c<=0) break;
            if(a*a+b*b==c*c) ret = max(ret,a*b*c);
        }
    }

    return ret;
}

int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    for (int i = 0; i<3005; i++) mem[i] = -5LL;
    int t, n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        cout<<func(n)<<endl;
    }

    return 0;
}
