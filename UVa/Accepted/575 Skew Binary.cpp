#include <iostream>
#include <cstring>
#define sz 1000
using namespace std;

int main()
{
    long long int n, i, j, sum, len, pow;
    char line[sz];

    while(cin>>line)
    {
        sum=0;

        len = strlen(line);

        for (i = len - 1, j = 1; i>=0; i--, j++)
        {
            if(line[i]=='1')
            {
                pow = 1;
                pow<<=j;
                pow--;
                sum+=pow;
            }
            else if(line[i]=='2')
            {
                pow = 1;
                pow<<=j;
                pow--;
                pow<<=1;
                sum+=pow;
            }
        }
        if(sum) cout<<sum<<endl;
        else break;
    }

    return 0;
}
