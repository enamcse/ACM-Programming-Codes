#include <iostream>
using namespace std;

int age[101];

int main()
{
    int n, i, j, t;

    while(cin>>n&&n)
    {
        for (i=1; i<101; i++)
            age[i] = 0;
        j = n;
        while(j--)
        {
            cin>>i;
            age[i]++;
        }

        for (i=1; i<101; i++)
        {
            for (j=0; j<age[i]; j++)
            {
                cout<<i;
                if(--n) cout<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}
