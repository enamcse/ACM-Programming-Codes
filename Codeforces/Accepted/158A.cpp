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

#define sz 100
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

vector<int>v(200);

int main()
{
    int n, k, x, solve;
    scanf("%d %d", &n, &k);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &x);
        v.pb(x);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    solve= v[k-1];
    x=k-1;
    if(solve>0){
    while(solve==v[x+1]&&x<v.size())
        x++;
        printf("%d", x+1);
    }
    else
    {
        while(x>0&&0==v[x-1])
        x--;
        printf("%d", x);
    }

	return 0;
}
