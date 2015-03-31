#include <iostream>
#define swap(x,y) x^=y^=x^=y;
using namespace std;

int main()
{
    int a,d,n,i,f;

    while(cin>>d>>n)
    {
        f = (int)d/n;
        cout<<"["<<f<<";";
        d = d - f * n;
        swap(d,n);
        f = (int)d/n;
        cout<<f;

        while(d%n!=0)
        {
            d = d - f * n;
            swap(d,n);
            f = (int)d/n;
            cout<<","<<f;
        }

        cout<<"]"<<endl;
    }

    return 0;
}
