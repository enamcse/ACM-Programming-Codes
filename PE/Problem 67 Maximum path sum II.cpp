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
#define sz 105
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("triangle.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

ll graph[sz][sz], sum[sz][sz];
int n;


ll rec(int x, int y)
{
    ll &ret = sum[x][y];
    if(ret!= -1) return ret;
//    ret = 0;
    if(x==n-1)
    {
        ret = graph[x][y];
        return ret;
    }
    ret = max(rec(x+1,y), rec(x+1,y+1));
    ret+= graph[x][y];
//    cout<<":"<<x<<" "<<y<<" "<<ret<<endl;
    return ret;
}

int main()
{
    fread;
    cin>>n;
    clr(sum, -1);
    for (int i = 0; i<n; i++)
        for (int j = 0; j<=i; j++)
            cin>>graph[i][j];
    cout<<rec(0,0)<<endl;
    return 0;
}
