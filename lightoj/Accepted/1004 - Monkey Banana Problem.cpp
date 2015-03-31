#include <iostream>
#include <cstring>
#define SZ 101
#define mem(a) memset(a,0,sizeof(a));
using namespace std;

int DP[SZ*SZ][SZ];

int main()
{
    int t, n, j, tn, p, caseno=1;

    cin>>t;

    for (int i=1; i<=t; i++)
    {
        cin>>n;
        for (j=0; j<n; j++)
        {
            for (int k = 0; k<=j; k++)
            {
                cin>>DP[j][k];
            }
            DP[j][j+1]=0;
        }
        for (int l=n-1; l>0; l--,j++)
        {
            for (int k=0; k<l; k++)
            {
                cin>>DP[j][k];
            }
            DP[j][l]=0;
        }

        for (j = 1; j<n; j++)
        {
            DP[j][0]+= DP[j-1][0];

            for (int k=1; k<=j; k++)
            {
                DP[j][k]+= max(DP[j-1][k],DP[j-1][k-1]);
            }
        }
        tn = (n<<1)-1;
        for (j = n, p=n-1; j<tn; j++,p--)
        {
            for (int k=0; k<p; k++)
            {
                DP[j][k]+= max(DP[j-1][k],DP[j-1][k+1]);
            }
        }

        cout<<"Case "<<caseno++<<": "<<DP[2*n-2][0]<<endl;
    }

    return 0;
}
