#include<cstdio>
#include<iostream>
using namespace std;

#define MAX 50
#define FO freopen("in.txt", "w", stdout)

int main()
{
    FO;
    cout<<MAX<<endl;
    for(int I = 1; I <= MAX; I++)
    {
        cout<<I<<endl;
        for(int J = 1; J <= I; J++)
            cout<<J<<endl;
        cout<<0<<endl;
    }
    return 0;
}
