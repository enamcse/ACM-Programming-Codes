#include <iostream>
using namespace std;

int a[100];
int s[100];

int main()
{
    int n,mx;
    cin>>n;
    for (int i =0 ; i<n; i++)
        cin>>a[i];
    s[0] = 1;
    for (int i =1; i<n; i++)
    {
        for (int j=i-1; j>=0; j--)
        {
            if(a[i]>a[j])
            {
                s[i] = max(s[i],s[j]+1);
            }
        }
        s[i]=max(s[i],1);
    }
    mx=0;
    for (int i = 0; i<n; i++)
        mx = max(mx,s[i]);
    cout<<mx<<endl;
    return 0;
}
