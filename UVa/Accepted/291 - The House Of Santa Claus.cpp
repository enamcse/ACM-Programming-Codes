/**
* H:\Dropbox\Code\UVa\291 - The House Of Santa Claus.cpp
* Created on: 2015-02-19-00.47.01, Thursday
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

vector<int>v[5];
vector<string>ans;
char s[10];
map< pair<int,int>,int >road;
int cnt;
bool paths[10];

void rec(int pos, int node)
{
    if(pos==8)
    {
        s[cnt] = 0;
        ans.pb(s);
        return ;
    }
    int n = v[node].size();
    for (int i = 0; i<n; i++)
    {
        if(!paths[road[{node,v[node][i]}] ])
            {
                paths[road[{node,v[node][i]}] ] = true;
                s[cnt++]=v[node][i]+'0'+1;
                rec(pos+1,v[node][i]);
                cnt--;
                paths[road[{node,v[node][i]}] ] = false;
            }
    }
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _

	v[0].pb(1);
	v[0].pb(2);
	v[0].pb(4);
	v[1].pb(0);
	v[1].pb(2);
	v[1].pb(4);
	v[2].pb(0);
	v[2].pb(1);
	v[2].pb(3);
	v[2].pb(4);
	v[3].pb(2);
	v[3].pb(4);
	v[4].pb(0);
	v[4].pb(1);
	v[4].pb(2);
	v[4].pb(3);

	road[ {0,1} ] = 0;
	road[ {1,0} ] = 0;
	road[ {1,2} ] = 1;
	road[ {2,1} ] = 1;
	road[ {2,3} ] = 2;
	road[ {3,2} ] = 2;
	road[ {3,4} ] = 3;
	road[ {4,3} ] = 3;
	road[ {4,0} ] = 4;
	road[ {0,4} ] = 4;
	road[ {4,2} ] = 5;
	road[ {2,4} ] = 5;
	road[ {2,0} ] = 6;
	road[ {0,2} ] = 6;
	road[ {4,1} ] = 7;
	road[ {1,4} ] = 7;
    s[cnt++]='1';
    rec(0, 0);
    n = ans.size();
    for (int i = 0; i<n; i++)
        cout<<ans[i]<<"\n";

   return 0;
}
