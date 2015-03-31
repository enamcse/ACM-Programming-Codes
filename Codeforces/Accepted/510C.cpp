/**
* H:\Dropbox\Code\Codeforces\510C.cpp
* Created on: 2015-02-02-23.16.43, Monday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 200005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
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

string s[105];

set<int>adj[26];
string ans="";
int ok[100];
int deg[26];




bool have_cycle()
{
    for (int i = 0; i<26; i++)
    {
        for (auto it = adj[i].begin(); it!=adj[i].end(); it++)
            deg[*it]++;
    }
    int k, tew=0;
    queue<int>q;
    for (int k = 0; k<26; k++)
    {
        if(deg[k]==0) q.push(k),tew++;
    }
    if(!tew) return true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        ans+=(char)(u+'a');
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
            if(--deg[*it]==0) q.push(*it);
    }
    return false;
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _

	cin>>n;

	for (int i = 0; i<n; i++)
	    cin>>s[i];
    for (int i = 0; i<=100; i++)
    {

        for (int j = 1; j<n; j++)
        {
            if(!ok[j])
            {
                if(s[j-1].size()<=i || s[j].size()<=i)
                {
                    if(s[j-1].size()>=s[j].size())
                    {
                        cout<<"Impossible";
                        return 0;
                    }
                    else {ok[j] = 1;continue;}
                }
                if(s[j-1][i]!=s[j][i])
                {
                    adj[ s[j-1][i] -'a' ].insert(s[j][i]-'a');
                    ok[j] = 1;
                }
            }
        }
    }


	if(have_cycle()||ans.size()<26)
    {
        cout<<"Impossible";
        return 0;
    }


    cout<<ans;


   return 0;
}
