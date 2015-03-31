#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int t,caseno=1,i;
    string a, b;

    cin>>t;
    getchar();
    while(t--)
    {
        getline(cin,a);
        getline(cin,b);
        if(a==b) cout<<"Case "<<caseno++<<": Yes"<<endl;
        else
        {
            i = 0;
            while(i<a.size())
            {
                if(a[i]==' ')
                {
                    a = a.substr(0,i) + a.substr(i+1);
                }
                else ++i;
            }
            if(a==b) cout<<"Case "<<caseno++<<": Output Format Error"<<endl;
            else cout<<"Case "<<caseno++<<": Wrong Answer"<<endl;
        }
    }
    return 0;
}
