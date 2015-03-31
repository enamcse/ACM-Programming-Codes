#include <iostream>
using namespace std;

int main()
{
    int t, x, y, n, x_a=0, x_b=0, y_a=0, y_b=0;

    cin>>n;
    while(n--)
    {
        cin>>t>>x>>y;
        if(t==1)
        {
            x_a+=x;
            y_a+=y;
        }
        else
        {
            x_b+=x;
            y_b+=y;
        }
    }

    if(x_a>=y_a) cout<<"LIVE"<<endl;
    else cout<<"DEAD"<<endl;

    if(x_b>=y_b) cout<<"LIVE"<<endl;
    else cout<<"DEAD"<<endl;

    return 0;
}
