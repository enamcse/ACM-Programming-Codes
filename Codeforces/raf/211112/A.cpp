#include <iostream>
using namespace std;

int main()
{
    int n, i;

    cin>>n;
    if(n<3) cout<<"-1";
    else if (n==3)
    {
        cout<<"2 3 1";
    }
    else
    {
        cout<<"2 3 1";
        for (i = 4; i<=n; i++)
            cout<<" "<<i;
    }

    return 0;
}
