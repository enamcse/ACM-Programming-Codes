#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int main()
{
    _
    int m,n, p;
    cin>>m>>n;
    if(m%2==0) p = (m>>1)*n;
    else if(n%2==0) p = (n>>1)*m;
    else if(m>2) p = ((m-1)>>1)*n+n/2;
    else if(n>2) p = ((n-1)>>1)*m+m/2;
    else p =0;
    cout<<p;
    return 0;
}
