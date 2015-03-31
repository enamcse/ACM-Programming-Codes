#include <iostream>
#include <cstring>
#define SZ 2147483647

using namespace std;

int fun(int x, int y, int z);
int fun(int x, int y);
int main()
{
    char a[100];
    int x,y,z;
    while(cin>>fun(x,y))
    {
        cout<<fun(x,y,z)<<" "<<fun(x,y)<<" "<<fun(y,z)<<endl;
    }
    return 0;
}

int fun(int x, int y, int z)
{
    return x+y+z;
}

int fun(int x, int y)
{
    return x-y;
}
