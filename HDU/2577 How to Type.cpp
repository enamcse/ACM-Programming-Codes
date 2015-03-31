#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, t, i, len;
    char arr[200];

    cin>>t;
    for (i=0; i<t; i++)
    {
        cin>>arr;
        len = strlen(arr);
        n=0;
        for (int j = 0; j<len; j++)
        {
            if(arr[j]>='A'&&arr[j]<='Z')
            {
                n+=2;
                if(!(j+1<len)) break;
                if(arr[j+1]>='a'&&arr[j+1]<='z') continue;
                j++;
                    while(arr[j]>='A'&&arr[j]<='Z'&&j<len) n++, j++;
                n++;
                j--;
            }
            else n++;
        }
        cout<<n<<endl;
    }

    return 0;
}
