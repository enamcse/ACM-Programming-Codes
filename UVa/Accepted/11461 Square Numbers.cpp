#include <iostream>
#define SZ 320

using namespace std;

int main()
{
    long int square[SZ], a, b, i, ub, lb, count;

    for (i=0; i<SZ; ++i)
    {
        square[i] = (i+1)*(i+1);
    }

    cin>>a>>b;

    while(a!=0 || b!=0)
    {
        i=0;
        count =lb = ub = 0;
        while(square[i]<=b)
        {
            if(square[i]>=a)
            {
                ub=i;
                while(square[i]<=b) i++;
                lb=i;
                break;
            }
            i++;
        }
        count = lb-ub;
        cout<<count<<endl;
        cin>>a>>b;
    }
    return 0;
}
