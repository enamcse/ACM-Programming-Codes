#include <iostream>
using namespace std;
int list[1002];
int main()
{
    int n, i, j, caseno=1, in;
    int sequence[1002];
    for (i=1; i<=1000; i++)
        for (j = 1; j <=i; j++)
        {
            if(i%j==0) list[i]++;
        }
    for (i=0;  ;i++)
    {

    }
    cin>>n;
    while(n--)
    {
        cin>>in;

    }
    return 0;
}
