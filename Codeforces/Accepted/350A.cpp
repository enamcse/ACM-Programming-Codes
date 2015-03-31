#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(name) (int) (name.size())
#define pb(a) push_back(a)
#define pp pop_back
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

vector<int>a,b;

int main()
{
    _
    int n, m,k;
    cin>>n>>m;
    for (int i = 0;i<n ;i++ )
    {
        cin>>k;
        a.pb(k);
    }
    for (int i = 0;i<m ;i++ )
    {
        cin>>k;
        b.pb(k);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a[n-1]>=b[0]) {cout<<-1;return 0;}
    k = a[0]*2;
        if(a[n-1]<=k&&b[0]>k)
        {
            cout<<k;
            return 0;
        }
    while(b[0]>k)
    {
        if(a[n-1]<=k)
        {
            cout<<k;
            return 0;
        }
        k++;
    }
    cout<<-1;
    return 0;
}
