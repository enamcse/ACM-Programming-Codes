#include <iostream>
using namespace std;

int main()
{
    int n,x, m, flag;

    while(cin>>n>>m)
    {

        flag = 1;
        x=n;

        if(x%m==0)
        {
            while(x%m!=1)
            {
                if(x%m==0)
                {
                    x/=m;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if(x!=1) flag = 0;
        }

        if(flag)
        {
            while(n%m!=1)
            {
                cout<<n<<" ";
                n/=m;
            }
            cout<<"1"<<endl;
        }
        else cout<<"Boring!"<<endl;

    }
    return 0;
}
