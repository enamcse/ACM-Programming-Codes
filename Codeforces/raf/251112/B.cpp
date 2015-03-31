#include <iostream>
using namespace std;

int main()
{
    int n, i, j;
    bool flag = true;
    cin>>n;

    if(n==1) cout<<-1;
    else if (n==2)
    {
        for (i = 10; i<100; i+=10)
            if(i%3==0&&i%7==0)
            {
                flag = false;
                cout<<i;
                break;
            }
        if(flag) cout<<-1;
    }
    else if (n==3)
    {
        for (i = 100; i<1000; i+=10)
            if(i%3==0&&i%7==0)
            {
                flag = false;
                cout<<i;
                break;
            }
        if(flag) cout<<-1;
    }
    else if (n==4)
    {
        for (i = 1000; i<10000; i+=10)
            if(i%3==0&&i%7==0)
            {
                flag = false;
                cout<<i;
                break;
            }
        if(flag) cout<<-1;
    }
    else if (n==5)
    {
        for (i = 10000; i<100000; i+=10)
            if(i%3==0&&i%7==0)
            {
                flag = false;
                cout<<i;
                break;
            }
        if(flag) cout<<-1;
    }
    else if (n==6)
    {
        for (i = 100000; i<1000000; i+=10)
            if(i%3==0&&i%7==0)
            {
                flag = false;
                cout<<i;
                break;
            }
        if(flag) cout<<-1;
    }
    else if (n==7)
    {
        for (i = 1000000; i<10000000; i+=10)
            if(i%3==0&&i%7==0)
            {
                flag = false;
                cout<<i;
                break;
            }
        if(flag) cout<<-1;
    }
    return 0;
}
