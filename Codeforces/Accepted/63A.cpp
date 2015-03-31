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

vector<string>rat;
vector<string>wc;
vector<string>man;
vector<string>c;


int main()
{
    _
    int n;
    string a, b;
    cin>>n;
    for (int i =0; i<n; i++)
    {
        cin>>a>>b;
        if(b=="rat") rat.pb(a);
        else if(b=="woman"||b=="child") wc.pb(a);
        else if(b=="man") man.pb(a);
        else c.pb(a);
    }
    n = rat.size();
    for (int i =0; i<n; i++)
        cout<<rat[i]<<endl;
    n = wc.size();
    for (int i =0; i<n; i++)
        cout<<wc[i]<<endl;
    n = man.size();
    for (int i =0; i<n; i++)
        cout<<man[i]<<endl;
    cout<<c[0]<<endl;
    return 0;
}
