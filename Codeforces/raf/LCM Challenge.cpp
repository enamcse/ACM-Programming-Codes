#include <iostream>
using namespace std;

int main()
{
    long long int a, b, c, n, d;

    while(cin>>n)
    {
        a = n-1;
        b = n-2;
        if(n%2==0)
        {
            c = n-3;
        }
        else
        {
            c = n;
        }
        if(n>=3) d = a*b*c;
        else if(n==2) d = 2;
        else d = n;

        cout<<d<<endl;
    }

    return 0;
}
