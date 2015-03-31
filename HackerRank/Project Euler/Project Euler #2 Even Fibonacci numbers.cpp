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

vector<ll>now, sums;

int main()
{
    ll num, fib1=0, fib2=1, sum =0, fib, last=4e17;
sums.pb(sum);
    while(1)
    {
        fib = fib1+fib2;
        if(fib>last) break;
        if(!(fib%2)){
            sum+=fib;
            now.pb(fib);
            sums.pb(sum);
        }
        fib1= fib2;
        fib2=fib;
    }
    int t;
    ll n;
    cin>>t;
    while(t--){
        cin>>n;
        if(binary_search(now.begin(), now.end(), n)){
            cout<< sums[ upper_bound(now.begin(), now.end(), n) - now.begin() ]<<endl;
        }
        else{
            cout<< sums[ lower_bound(now.begin(), now.end(), n) - now.begin() ]<<endl;
        }
    }
    return 0;
}
