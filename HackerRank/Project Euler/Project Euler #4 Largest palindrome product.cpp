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

bool palindrome(int n)
{
    int p,q;
    p = (n/100000)%10;
    q = n%10;
    if(p!=q) return false;
    p = (n/10000)%10;
    q = (n/10)%10;
    if(p!=q) return false;
    p = (n/1000)%10;
    q = (n/100)%10;
    if(p!=q) return false;
//    cout<<"|"<<n<<"|"<<endl;
    return true;
}

vector<int>v;

int main()
{
    int n, ma=0;
    char num[20];
    for (int i=101;i< 1000; i++)
        for (int j = i; j<1000; j++)
        {
            n = i*j;
            if(n/100000==0) continue;
            if(palindrome(n)) v.pb(n);
        }

//    for (int i = 0; i<100; i++)
//    {
//        cout<<v[i]<<" ";
//    }


    int t;
    cin>>t;
    sort(v.begin(),v.end());
    while(t--){
        cin>>n;

        cout<< v[ lower_bound(v.begin(), v.end(), n) - v.begin()-1 ]<<endl;
    }


    return 0;
}
