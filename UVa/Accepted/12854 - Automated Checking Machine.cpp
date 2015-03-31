/**
* H:\Dropbox\Code\UVa\12854 - Automated Checking Machine.cpp
*
* Created on: 2014-12-02-02.03.16, Tuesday
* Author: Enamul Hassan
* Verdict: NOT SOLVED
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int a[5], b[5];

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
_
    bool flag;
    while(cin>>a[0])
    {
        flag = true;
        for (int i = 1; i<5; i++)
            cin>>a[i];
        for (int i = 0; i<5; i++)
            cin>>b[i];

        for (int i = 0; i<5; i++)
            if(!(a[i]^b[i])) flag = false;
            if(flag) cout<<"Y\n";
            else cout<<"N\n";
    }
    return 0;
}
