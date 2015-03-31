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

int num[111];

int main()
{
    _
    int n, e=0,o=0;
    cin>>n;
    for (int i = 0; i<n; i++)
        cin>>num[i];
    for (int i = 0; i<3; i++)
        if(num[i]%2) o++;
        else e++;
    if(o>e)
    {
        for (int i = 0; i<n; i++)
            if(num[i]%2==0)
            {
                cout<<i+1;
                break;
            }
    }
    else
    {
        for (int i = 0; i<n; i++)
            if(num[i]%2)
            {
                cout<<i+1;
                break;
            }
    }
    return 0;
}
