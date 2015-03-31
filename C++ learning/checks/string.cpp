#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    char ch[] = {"This is an array"};
    string a="This is me!", b = "that is you!", d= "abcdefghi",e,f;
    string c = a + " and " + b;
    cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;
    b = a = c;
    cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;
    b = ch;
    cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;
    //ch = c;
    cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;

    cout<<"This is :"<<endl;
    e = d.substr(4,4);
    f = d.substr(1);
    cout<<"e = "<<e<<"f = "<<f;
    return 0;
}
