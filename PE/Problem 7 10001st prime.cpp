#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#define sz 1000000
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

bool prime[sz];
vector<int>v;
void seive()
{
    for (int i = 2; i<sz; i++)
        prime[i]=true;

    for (int i = 2; i<sz; i++)
        if(prime[i]==true)
            for (int j = 2; j*i<sz; j++)
                prime[i*j]=false;
    return;
}

int main()
{
    seive();
    for (int i = 0; i<sz; i++)
        if(prime[i]) v.pb(i);

//    for (int i = 0; i<10; i++)
//        cout<<v[i]<<endl;

    cout<<v[10000]<<endl;
    return 0;
}
