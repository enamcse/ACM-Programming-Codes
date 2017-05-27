/**
* E:\Dropbox\Code\Others\Habijabis\20160218001.cpp
* Created on: 2016-02-18-22.11.22, Thursday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((ll)a.size())
#define sz 200005
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<": ";
#define mod 1000000007

using namespace std;

int dp[2][1010][1010];
int t, n,m;
pair<int,int>arr[1010];

int rec(int mov, int pos, int last)
{
    //cout<<">>"<<mov<<" "<<pos<<" "<<last<<endl;
    if(pos==m) return 0;
    int &ret = dp[mov][pos][last];
    if(ret!=-1) return ret;
    //cout<<"ret = "<<ret<<endl;
    ret = 1e9;
    if(pos==0)
    {
        ret = min(ret, rec(0,1,last) + abs( arr[pos].first - arr[pos].second ) );
        ret = min(ret, rec(1,1,last) + abs( arr[pos].first - arr[pos].second ));
        return ret;
    }
    ///
    ret = min(ret, rec(mov,pos+1, last) + abs( arr[pos].first - arr[pos-1].second )+ abs( arr[pos].first - arr[pos].second ));
    if(last>pos) ret = min(ret, rec(!mov,pos+1, pos-1) + abs( arr[pos].first - arr[pos].second ));
    else ret = min(ret, rec(!mov,pos+1, pos-1) + abs( arr[pos].first - arr[last].second )+ abs( arr[pos].first - arr[pos].second ));
    return ret;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */


    cin>>t;

    while(t--)
    {
        clr(dp,-1);
        cin>>n>>m;

        for(int i = 0; i<m; i++) cin>>arr[i].first>>arr[i].second;
        cout<<rec(0,0,1009)<<"\n";
    }

    return 0;
}
