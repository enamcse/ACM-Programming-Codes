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
    ll a, n, sum;
    int t;
    cin>>t;

    while(t--)
    {
        cin>>n;
        sum=0;
        for (int i = 3; i<n; i++)
        {
            if(!(i%3)||!(i%5)) sum+=i;
        }
        cout<<sum<<endl;
    }

    return 0;
}
