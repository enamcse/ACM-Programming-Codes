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
    int n, re;
    string str = "abcd";
    cin>>n;
    re = (n>>2);
    for (int i = 0; i<re; i++)
        cout<<str;
    n-=(re<<2);
    if(n==1) cout<<"a";
    else if(n==2) cout<<"ab";
    else if(n==3) cout<<"abc";
    return 0;
}
