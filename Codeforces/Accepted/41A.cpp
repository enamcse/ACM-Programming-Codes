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
    string a, b;
    int len;
    bool flag = true;
    cin>>a>>b;
    if(a.size()!=b.size())
    {
        cout<<"NO";
        return 0;
    }
    len = a.size();
    for (int i = 0; i<len; i++)
        if(a[i]!=b[len -i-1])
        {
            flag = false;
            cout<<"NO";
            break;
        }
    if(flag) cout<<"YES";
    return 0;
}
