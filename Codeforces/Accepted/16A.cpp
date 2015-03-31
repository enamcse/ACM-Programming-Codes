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

string rows[sz];

int main()
{
    _
    int n, m, pre=-1;
    bool flag = true;
    cin>>n>>m;
    for (int i = 0; i<n; i++)
        cin>>rows[i];
    for (int j =0; j<n; j++)
        for (int i = 1; i<m; i++)
            if(rows[j][i]!=rows[j][0])
            {
                flag = false;
                break;
            }
    for (int i = 0; i<n; i++)
    {
        if(rows[i][0]==pre)
        {
            flag = false;
            break;
        }
        pre = rows[i][0];
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
    return 0;
}
