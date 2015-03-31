#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int main()
{
    _
    int n, x, y, z,a,b,c;
    cin>>n;
    x=y=z=0;
    for (int i = 0; i<n; i++)
    {
        cin>>a>>b>>c;
        x+=a;
        y+=b;
        z+=c;
    }
    if(x||y||z) cout<<"NO";
    else cout<<"YES";
    return 0;
}
