/**
* H:\Dropbox\Code\HackerCup\2015\Cooking the Books15 points.cpp
* Created on: 2015-01-11-22.14.57, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("cooking_the_books.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _
	char temp;
	string s, now;
	bool flag;
	cin>>t;
    vector<string>ans;
	while(t--)
    {
        s.clear();
        cin>>s;
        n = s.size();
        ans.clear();
        ans.pb(s);
        for (int i = 0; i<n; i++)
        {
            for (int j = i+1; j<n; j++)
            {
                if(s[j]<s[i])
                {
                    if(i==0&&s[j]=='0') continue;
                    now = s;
                    now[j] = s[i];
                    now[i] =  s[j];
                    ans.pb(now);
                }
            }
        }
        sort(all(ans));

        cout<<"Case #"<<cas++<<": "<<ans[0]<<" ";


        ans.clear();
        ans.pb(s);
        for (int i = 0; i<n; i++)
        {
            for (int j = i+1; j<n; j++)
            {
                if(s[j]>s[i])
                {
                    now = s;
                    now[j] = s[i];
                    now[i] =  s[j];
                    ans.pb(now);
                }
            }
        }
        sort(all(ans));


        cout<<ans[ans.size()-1]<<"\n";
    }

   return 0;
}
