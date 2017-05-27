/**
* E:\Dropbox\Code\Others\Habijabis\20160222001.cpp
* Created on: 2016-02-22-06.31.23, Monday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include<iostream>
using namespace std;

int main()
{
    int a=35,b=0,x=0;
    for(; a!=0;)
    {
        b=(b*10)+(a%2);
        a/=2;
    }
    cout<<b<<endl;
    for(int i=0; i<=2; i++)
        x=(x<<1)|1;
    x=(x<<2);
    cout<<x<<endl;
    x=x&b;
    cout<< x<< endl;
    x=(x>>2);
    cout<< x<< endl;
    return 0;
}
