#include <iostream>
using namespace std;

int main()
{
    long long int a, b, c, d, t, p, q,min;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a>b) cout<<"-1"<<endl;
        else if(a==b) cout<<a<<" "<<b<<endl;
        else
        {
            min = 2147483647;
            p = a;
            q = b;
            while(p<q)
            {
                if((p&q)==a&&(p|q)==b)
                {
                    if(q-p<min)
                    {
                        c = p;
                        d = q;
                        min = q-p;
                    }
                }
                p++;
                q--;
            }
            cout<<c<<" "<<d<<endl;
        }
    }
    return 0;
}
