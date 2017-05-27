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

ll graph[sz][sz];

ll n;

ll rec(ll x, ll y)
{
        ll &ret = graph[x][y];
    if(ret!=-1) return ret;
    if(x==n&&y==n)
    {
        ret = 1;
        return ret;
    }

    if(x==n&&y<n)
    {
        ret = rec(x,y+1);
        return ret;
    }
    if(y==n&&x<n)
    {
        ret = rec(x+1,y);
        return ret;
    }
    if(x<n&&y<n)
    {
        ret = rec(x+1,y)+rec(x,y+1);
        return ret;
    }
//    if(x<n)
//    {
//        return rec(x+1,y);
//    }
//    if(y<n)
//    {
//        return rec(x,y+1);
//    }
}


int main()
{

    while(cin>>n)
    {
        clr(graph,-1);
        cout<<rec(0,0)<<endl;
    }
    return 0;
}
