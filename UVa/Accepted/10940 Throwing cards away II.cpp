#include <iostream>
#define sz 500001
using namespace std;

int item[sz];

int main()
{
    int i, j, t, power[20], a = 1, cnt,pw_cnt=1;

    for (i=0; i<20; i++)
    {
        power[i] = a;
        a<<=1;
    }
    item[1] = 1;
    for (i=2; i<sz;)
    {
        for (j=2; j<=power[pw_cnt]&&i<sz; j+=2)
        {
            item[i++] = j;
        }
        pw_cnt++;
    }
    cin>>t;
    while(t)
    {
        cout<<item[t]<<endl;
        cin>>t;
    }
    return 0;
}
