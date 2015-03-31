#include <iostream>
#include <cstring>
using namespace std;
long long fn(long long n);

long long DP[10001], n;

int main()
{
    int n, t, i;
    cin>>t;
    for (int j = 1; j<=t; j++)
    {
        memset(DP,-1,sizeof(DP));
        for (i=0; i<6; i++)
            cin>>DP[i];
        cin>>n;
        cout<<"Case "<<j<<": "<<fn(n)%10000007<<endl;
    }
    return 0;
}

long long fn(long long n)
{
    long long &ret = DP[n];
    if(ret!=-1) return ret;
    return ret = (fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6))%10000007;
}
