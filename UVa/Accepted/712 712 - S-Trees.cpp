#include <iostream>
#define sz 200
using namespace std;

int main()
{
    int m,n,i,k,st=1,l;
    char x[sz],s[sz],input[10][3];
    cin>>n;
    while(n)
    {
        for(i=0; i<n; i++)
            cin>>input[i];
        cin>>s;
        cout<<"S-Tree #"<<st++<<":"<<endl;
        cin>>m;
        while(m--)
        {
            cin>>x;
            k=1;
            for(i=0; i<n; i++)
            {
                l=input[i][1]-'0'-1;
                if(x[l]-'0')
                    k=(k<<1)+1;
                else
                    k<<=1;
            }
            l=k-(1<<n);
            cout<<s[l];
        }
        cout<<endl<<endl;
        cin>>n;
    }
    return 0;
}
