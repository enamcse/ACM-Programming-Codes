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

bool data[3001];

int main()
{
    _
    int n,x;
    clr(data,false);
    cin>>n;
    for (int i =0; i<n; i++)
    {
        cin>>x;
        data[x] = true;
    }
    x = 1;
    while(data[x]==true)x++;
    cout<<x;
    return 0;
}
