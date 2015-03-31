/**
* H:\Dropbox\Code\UVa\102 - Ecological Bin Packing.cpp
* Created on: 2015-01-02-15.07.52, Friday
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

int bottles[3][3];
map<int,char>mp;




int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1, mn;
    _
    mp['B'] = 0;
    mp['G'] = 1;
    mp['C'] = 2;
    string standard = "BCG";
	while(cin>>bottles[0][0]>>bottles[0][1]>>bottles[0][2])
    {
        mn = inf;
        for (int i = 1; i<3; i++)
            for (int j = 0; j<3; j++)
                cin>>bottles[i][j];
        string v=standard, ans;
        do
        {
            int now=0;
            for (int i = 0; i<3; i++)
            {
                for (int j = 0; j<3; j++)
                {
                    if(mp[ v[i] ]==j) continue;
                    now+=bottles[i][j];
                }
            }
            if(now<mn)
            {
                mn = now;
                ans = v;
            }
        }
        while(next_permutation(all(v)));
        cout<<ans<<" "<<mn<<"\n";
    }


   return 0;
}
