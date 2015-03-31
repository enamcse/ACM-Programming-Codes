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

int num[101];

int main()
{
    _
    int n, k;
    cin>>n;
    for (int i =0; i<n; i++)
    {
        cin>>k;
        num[k]++;
    }
    k=0;
    for (int i=1; i<101; i++)
    {
        k+=(num[i]>>1);
//        cout<<k<<" ";
    }
    k>>=1;
    cout<<k<<endl;
    return 0;
}
