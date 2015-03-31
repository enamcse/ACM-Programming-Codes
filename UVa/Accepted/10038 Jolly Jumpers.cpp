#include <iostream>
#define sz 3500

bool sequence[sz], flag;

using namespace std;
int main()
{

    int dif, t, a, b, i;
    while(cin>>t)
    {
        flag = true;
        cin>>a;
        for (i=1; i<t; i++)
        {
            sequence[i] = true;
        }

        for (i=1; i<t; i++)
        {
            cin>>b;
            dif = b - a;
            a = b;
            dif = dif>0?dif:-dif;
            if(dif<sz)sequence[dif] = false;
        }

        for (i=1; i<t; i++)
        {
            if(sequence[i] == true)
            {
                flag = false;
                break;
            }
        }

        if(flag) cout<<"Jolly"<<endl;
        else cout<<"Not jolly"<<endl;
    }

    return 0;
}
