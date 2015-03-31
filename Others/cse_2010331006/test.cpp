#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

string s;

int main()
{
    stringstream ss;
    cin >>s;
    cout << s << endl;

    char str[100];

    while(scanf(" %[^\n]",str)==1)
    {
        str << s;
        cout << s;
    }
    return 0;
}
