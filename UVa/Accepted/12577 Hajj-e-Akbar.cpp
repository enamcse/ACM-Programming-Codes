#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char hajj[] = "Hajj", umrah[] = "Umrah", input[20],c;
    int t=1;
    cin>>input;
    while(strcmp(input, "*")==1)
    {
        if(strcmp(input, hajj)==0) cout<<"Case "<<t++<<": Hajj-e-Akbar"<<endl;
        else cout<<"Case "<<t++<<": Hajj-e-Asghar"<<endl;
        cin>>input;
    }

    return 0;
}
