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
    string str;
    int n, t, cnt = 0;
    cin>>n>>str;
    t = str.size();
    int i = n;
    if(t<4) cnt = 0;
    else
    {
        while(i<t)
        {
            if(str[i-1]=='a'&&str[i-2]=='a'&&str[i-3]=='a') cnt++;
            else if (str[i-1]=='b'&&str[i-2]=='b'&&str[i-3]=='b') cnt++;
            i+=n;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
