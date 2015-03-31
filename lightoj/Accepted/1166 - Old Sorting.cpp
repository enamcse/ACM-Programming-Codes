#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 111
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int num[sz];

int main()
{
    _
    int n, t, cas=1, change,cnt;
    cin>>n;
    while(n--)
    {
        cin>>t;
        for (int i =0; i<t; i++)
            cin>>num[i];
        cnt=0;
        while(1)
        {
            int i;
            for (i=0; i<t; i++)
            {
                if(num[i]!=i+1)
                {
                    change = num[i];
                    num[i] = num[change-1];
                    num[change-1] = change;
                    cnt++;
                    break;
                }
            }
            if(i==t) break;
        }
        cout<<"Case "<<cas++<<": "<<cnt<<endl;
    }
    return 0;
}
