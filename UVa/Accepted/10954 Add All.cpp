#include <iostream>
using namespace std;

int main ()
{
    int sum, i, t,n, num[5000], min1, min2, posm1, posm2;
    cin>>t;
    while(t)
    {
        for (i=0; i<t; i++)
        {
            cin>>num[i];
        }
        sum = 0;
        n = t;
        while(n!=1)
        {
            min1 = num[0]<num[1]?num[0]:num[1];
            min2 = num[0]>num[1]?num[0]:num[1];

            if(num[0]<num[1])
            {
                posm1 = 0;
                posm2 = 1;
            }
            else
            {
                posm1 = 1;
                posm2 = 0;
            }

            for (i=2; i<n; i++)
            {
                if(num[i]<min1)
                {
                    min2 = min1;
                    posm2 = posm1;
                    min1 = num[i];
                    posm1 = i;
                }
                else if(num[i]<min2)
                {
                    min2 = num[i];
                    posm2 = i;
                }
            }

            if(posm2 > posm1)
            {
                sum += num[posm1] = num[posm1] + num[posm2];
                i = posm2;
            }
            else
            {
                sum += num[posm2] = num[posm1] + num[posm2];
                i = posm1;
            }

            for (--n; i<n; i++)
            {
                num[i] = num[i+1];
            }
        }

        cout<<sum<<endl;
        cin>>t;
    }
    return 0;
}
