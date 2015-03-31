#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 3010
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int fact[sz],cum[sz];

int main()
{
    _
    for (int i =2; i<3010; i++)
    {
        for (int j = 2; j<i; j++)
        {
            if(i%j==0&&!fact[j]) fact[i]++;
        }
    }
    for (int i = 2; i<3010; i++)
    {

        if(fact[i]==2) cum[i] = cum[i-1]+1;
        else cum[i] = cum[i-1];
//        cout<<i<<" "<<fact[i]<<" "<<cum[i]<<endl;
    }
    int n;
    cin>>n;
    cout<<cum[n];
    return 0;
}
