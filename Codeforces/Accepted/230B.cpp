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

#define sz 1000010
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
bool prime[sz];

vector<ll>prime_square;

void seive()
{
    for (int i = 3; i<1010; i+=2)
    {
        for (int j = 3; j*i<sz; j+=2)
        {
            prime[i*j]=true;
        }
    }
    prime_square.pb(4);
    for (ll i = 3; i<sz; i+=2)
        if(!prime[i])prime_square.pb(i*i);
    return;
}

int main()
{
    int n, len;
    ll num, root;
    seive();
//    for (int i = 0; i<prime_square.size(); i++)
//        cout<<prime_square[i]<<" ";
    cin>>n;
    while(n--)
    {
        cin>>num;
        if(binary_search(prime_square.begin(),prime_square.end(),num)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
	return 0;
}
