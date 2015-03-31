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
    string s;
    stack<char>st;
    cin>>s;
    int len = s.size();
    for (int i = 0; i<len; i++)
    {
        if(st.empty()) st.push(s[i]);
        else if(st.top()==s[i]) st.pop();
        else st.push(s[i]);
    }
    if(st.empty()) cout<<"Yes";
    else cout<<"No";
    return 0;
}
