/**
* H:\Dropbox\Code\HackerCup\2015\New Year's Resolution30 points.cpp
* Created on: 2015-01-11-23.44.59, Sunday
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
#define fread freopen("new_years_resolution.txt","r",stdin)
#define fwrite freopen("output2.txt","w",stdout)
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

int n;
bool flag;
struct tup{
    int pos,a, b, c;
};
map<pair< pair<int,int>, pair<int,int>  >, bool >mp;

tup tews[50];

void rec(int pos, int a, int b, int c)
{
    if(flag) return;
    if(a<0||b<0||c<0) return;
    if(pos==n)
    {
        if(!a&&!b&&!c) flag = true;
        return;
    }
    pair< pair<int,int>, pair<int,int>  > now;
    now.first.first = pos;
    now.first.second = a;
    now.second.first = b;
    now.second.second = c;
    if(mp.find(now)!=mp.end()) return;
    mp[now]=true;
    rec(pos+1,a,b,c);
    rec(pos+1,a-tews[pos].a,b-tews[pos].b,c-tews[pos].c);
}


int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    int t, m, cas=1;
    int a,b,c;
    _

	cin>>t;


	while(t--)
    {
        cin>>a>>b>>c;
        flag = false;
        mp.clear();

        cin>>n;

        for (int i = 0; i<n; i++)
            cin>>tews[i].a>>tews[i].b>>tews[i].c;


        rec(0,a,b,c);


        if(flag) cout<<"Case #"<<cas++<<": yes\n";
        else cout<<"Case #"<<cas++<<": no\n";
    }

   return 0;
}
