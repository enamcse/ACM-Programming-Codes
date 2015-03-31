#include <iostream>
using namespace std;

int main()
{
    int t, n, p, q, w[100],i,sum,count,caseno=1;
    cin>>t;
    while(t--)
    {
        sum=count=0;
        cin>>n>>p>>q;
        for(i=0;i<n;i++)
        {
            cin>>w[i];
        }

        for (i=0; count<p&&sum<q&&i<n;i++)
        {
            sum+=w[i];
            if(sum>q)
            {
                sum-=w[i];
                break;
            }
            count++;
        }

        cout<<"Case "<<caseno++<<": "<<count<<endl;
    }
    return 0;
}
