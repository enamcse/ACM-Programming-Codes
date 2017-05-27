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

bool prime[1000000];

void seive()
{
    for (int i = 2; i<1000000; i++)
        prime[i]=true;

    for (int i = 2; i<1000000; i++)
        if(prime[i]==true)
            for (int j = 2; j*i<1000000; j++)
                prime[i*j]=false;
    return;
}

int main()
{
    ll n;
    seive();

    for (int i=2; i<775147; i++)
    {
        if(prime[i]==false) continue;
        if(!(600851475143%i)) n = i;
    }
    cout<<n<<endl;

    return 0;
}
