/**
* H:\Dropbox\Code\lightoj\1092 - Lighted Panels.cpp
* Created on: 2015-01-31-05.28.33, Saturday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 8
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
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

int rowmask[sz],n,m, dp[sz][(1<<sz)][(1<<sz)];

int rec(int row, int parmask, int curmask)
{
    if(row==n) return parmask?inf:0;
    int &ret = dp[row][parmask][curmask];
    if(ret!=-1) return ret;
    ret = inf;

    for (int i = 0; i<(1<<m); i++)
    {
        int rows[3];
        rows[0]=parmask;
        rows[1]=curmask;
        rows[2]=rowmask[row+1];
        for (int j = 0; j<m; j++)
            if(i&(1<<j))
            {
                for (int p = max(0,row-1); p<min(n,row+2); p++)
                    for (int q = max(0,j-1); q<min(m,j+2); q++)
                        rows[p-row+1]^=(1<<q);
            }
        if(rows[0]==0) ret = min(ret,__builtin_popcount(i) + rec(row+1,rows[1],rows[2])); ///parent mask ok
    }
    return ret;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t,  cas=1,x,y;
    _
    string s;
	cin>>t;

	while(t--)
    {
        clr(dp,-1);
        cin>>n>>m;

        for (int i = 0; i<n; i++)
        {
            cin>>s;
            rowmask[i] = 0;
            for (int j = 0; j<m; j++)
                rowmask[i]|= ((s[j] == '.')<<j);
        }

        int ans = inf;
        ans = rec(0,0,rowmask[0]);

        cout<<"Case "<<cas++<<": ";
        if(ans<inf) cout<<ans<<"\n";
        else cout<<"impossible\n";

    }


   return 0;
}
