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
    string in;
    int t,n, k=0, cas=1, x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        k=0;
        cout<<"Case "<<cas++<<":"<<endl;
        while(n--)
        {
            cin>>in;
            if(in=="donate")
            {
                cin>>x;
                k+=x;
            }
            else cout<<k<<endl;
        }
    }
    return 0;
}
