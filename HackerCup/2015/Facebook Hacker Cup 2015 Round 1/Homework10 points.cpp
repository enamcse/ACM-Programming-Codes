/**
* H:\Dropbox\Code\HackerCup\2015\Facebook Hacker Cup 2015 Round 1\Homework10 points.cpp
* Created on: 2015-01-18-00.09.13, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 10000010
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("homework.txt","r",stdin)
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

vector<int>facts[sz];

int ans[sz][9];


int main()
{
#ifdef ENAM
    	fread;
	fwrite;
#endif // ENAM
    int t, n, m, cas=1, maxd = (1e7+5),a,b,k;
    _

  // Generates the divisors
  for(int i=2;i<=maxd;i++) if(facts[i].size()==0)
      for(int j=i;j<=maxd;j+=i) facts[j].pb(i);

    for (int i = 1; i<maxd; i++)
    {
        for (int j = 0; j<=8; j++)
            ans[i][j]+=ans[i-1][j];
        ans[ i ][ facts[i].size() ]++;
    }

    cin>>t;


    while(t--)
    {
        cin>>a>>b>>k;
        a--;
        cout<<"Case #"<<cas++<<": ";
        if(k>8) cout<<"0\n";
        else cout<<ans[b][k]-ans[a][k]<<"\n";
    }



   return 0;
}
