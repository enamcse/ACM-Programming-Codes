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

map<int,vector<string> >m;

int main()
{
    _
    int t,n,cas=1,a,b,c,v;
    string str;
    cin>>t;
    while(t--)
    {
        m.clear();
        cin>>n;
        while(n--)
        {
            cin>>str>>a>>b>>c;
            v = a*b*c;
            m[v].pb(str);
        }
        map<int,vector<string> >:: iterator s, e;
        s = m.begin();
        e = m.end();
        e--;
        if(*s==*e) cout<<"Case "<<cas++<<": no thief"<<endl;
        else cout<<"Case "<<cas++<<": "<<(e->second[0])<<" took chocolate from "<<(s->second[0])<<endl;
    }
    return 0;
}
