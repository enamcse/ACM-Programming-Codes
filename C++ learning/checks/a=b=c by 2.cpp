#include <iostream>

using namespace std;

int main()
{
    int a=10, b=20 , c=40, d=80;
    cout<<"a=b=c/2 case: "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    a=b=c/2;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

    a=10, b=20 , c=40, d=80;
    cout<<"a=b=d/2 case: "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    a=b=d/2;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;


    a=10, b=20 , c=40, d=80;
    cout<<"a=b=d=a/2 case: "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    a=b=d=a/2;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

    a=10, b=20 , c=40, d=80;
    cout<<"d+=a+=b+=c+=++a/2 case: "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    d+=a+=b+=c+=++a/2;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return 0;
}
