#include <iostream>
using namespace std;

int main()
{
    long int n, x, sum =0,i;
    cin>>n;
    for (i=0; i<n; i++)
    {
        cin>>x;
        sum+=x;
    }
        if(sum%n) cout<<n-1;
        else cout<<n;

    return 0;
}
