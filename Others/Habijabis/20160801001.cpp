#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main()
{
    _
    cout<<"I hate ";
    int n;
    cin>>n;
    for (int i = 1; i<n; i++)
    {
        if(i%2) cout<<"that I love ";
        else cout<<"that I hate ";
    }

    cout<<"it\n";
}
