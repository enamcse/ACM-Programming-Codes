#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 150
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int h[sz], dif[sz];

int main()
{
    _
    int n, mn = inf;
    cin>>n;
    for (int i =0; i<n; i++)
    {
        cin>>h[i];
    }
    for (int i = 0; i<n-1; i++)
    {
        dif[i] = abs(h[i]-h[i+1]);
        mn = mn<dif[i]?mn:dif[i];
    }
    dif[n-1] = abs(h[n-1]-h[0]);
    mn = mn<dif[n-1]?mn:dif[n-1];
    for (int i =0; i<n; i++)
    {

//        cout<<dif[i]<<" "<<mn<<endl;
        if(mn==dif[i])
        {
            if(i==n-1) cout<<1<<" "<<n;
            else cout<<i+1<<" "<<i+2;
            break;
        }
    }
    return 0;
}
