/**
* E:\Dropbox\Code\Others\Habijabis\20160617001_pow_reproduce.cpp
* Created on: 2016-06-17-00.28.36, Friday
* Verdict: Not Solved
* Author: Enamul Hassan
**/
#include <bits/stdc++.h>
using namespace std;

void print_binary(long double y)
{
    const long double x = y;
    unsigned char     a[sizeof(long double)];

    copy(
        reinterpret_cast<const unsigned char*>(&x),
        reinterpret_cast<const unsigned char*>(&x) + sizeof(long double),
        &a[0]
    );
    for (auto el : a)
    {
        bitset<8>k(el);
        cout << k.to_string() ;
    }

    cout << endl;
}

int main()
{
    int a[] = {20,29,31}, res=0;
    for(int i = 0; i<3; i++)
    {
        cout<<"i = "<<i<< ", a["<<i<< "] = "<<a[i]<<"\npow(" << a[i] <<","<<i+1 << "):\nBinary: ";
        long double temp = pow(a[i],i+1);
        print_binary(temp);
        res+=temp;
        cout<<setprecision(50)<<fixed<< "Decimal: " <<temp <<", Result = "<<res<<endl;
    }
    return 0;
}
