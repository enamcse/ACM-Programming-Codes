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
    ll k, l, n=1,i;
    cin>>k>>l;
    for (i=1; n<l; i++)n*=k;
    if(n==l)cout<<"YES"<<endl<<i-2;
    else cout<<"NO";
    return 0;
}
