#include <iostream>
using namespace std;

int main()
{
    int n, out, l=0, r=0,i, p, q, mi, ma;

    cin>>n;

    for (i=0; i<n; i++)
    {
        cin>>p>>q;
        if(p==1)
        {
            l++;
        }
        if(q==1)
        {
            r++;
        }
    }
    mi = min(l,r);
    ma = max(l,r);
    out = n-ma+mi;
    cout<<out;


    return 0;
}
