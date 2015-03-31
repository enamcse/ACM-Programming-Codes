#include <iostream>
#define SZ 1005

using namespace std;

int main()
{
    int t,n,m, series[SZ];
    cin>>t;

    while(t--)
    {
        int i,j,temp,count;
        i = count= 0;
        cin>>m;
        n = m;
        while(m--) cin>>series[i++];

        for (i = 0; i<n-1; ++i)
        {
            for (j = i+1; j<n; ++j)
            {
                if(series[j]<series[i])
                {
                    temp = series[j];
                    series[j] = series[i];
                    series[i] = temp;
                    count++;
                }
            }
        }

        cout<<"Optimal train swapping takes "<<count<<" swaps."<<endl;
    }


    return 0;
}
