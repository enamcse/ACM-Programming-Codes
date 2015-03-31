#include <iostream>
using namespace std;

int GCD(int a,int b)
{
    if(a%b==0) return b;
    GCD(b,a%b);
}

int main()
{
    int i,j,n, G=0;

    cin>>n;
    while(n)
    {
        G = 0;
        for(i=1; i<n; i++)
            for(j=i+1; j<=n; j++)
            {
                G+=GCD(i,j);
            }
        cout<<G<<endl;
        cin>>n;
    }
}

