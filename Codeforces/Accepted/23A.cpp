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
    int mx = 0, len;
    string st;
    cin>>st;
    len = st.size();
    for (int i =0; i<len; i++)
    {
        for (int j = i+1; j<len; j++)
        {
            if(st[i]==st[j])
            {
                int k=1;
                mx=mx>k?mx:k;
                if(k+j>=len) break;
                while(st[i+k]==st[j+k])
                {
                    k++;
                    if(k+j>=len) break;
                }
                mx=mx>k?mx:k;
            }
        }
    }
    cout<<mx;
    return 0;
}
