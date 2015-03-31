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

bool prime[2000000];

vector<ll>v;

void seive()
{
    int sq = sqrt(2000000);
    for (int i = 3; i<=sq; i+=2)
         if(!prime[i])
            for (int j = i*i; j<2000000; j+=i+i)
                prime[j]=true;
    v.pb(2);
    for (int i = 3; i<2000000; i+=2)
       if(!prime[i]) v.pb(i);
    return;
}

int main()
{
    ll n, m;
    seive();
    int t, sq,i, len;
    cin>>t;
    len = v.size();

    while(t--)
    {
        cin>>n;
        m = n;
        sq = sqrt(m);
        i = 0;

        while(i<len&&v[i]<=sq&&m>1){

            if(m%v[i]==0){
                n = v[i];
                while(m%v[i]==0) m/=v[i];

            }
            i++;
        }
        if(m>1)cout<<m<<endl;
        else cout<<n<<endl;
    }


    return 0;
}
