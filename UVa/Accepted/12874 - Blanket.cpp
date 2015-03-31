/**
* H:\Dropbox\Code\UVa\12874 - Blanket.cpp
*
* Created on: 2014-11-30-03.44.44, Sunday
* Author: Enamul Hassan
* Verdict: SOLVED
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100005
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
#define MAX 1000010
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int arr[17][17];
int result[MAX], ans[MAX/10+10];

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    _
    int t, n, m, a, b;

    cin>>t;

    while(t--)
    {
        clr(arr,0);
        clr(ans,0);
        cin>>n>>m;

        for (int i = 0; i<=m; i++)
            result[i]=0;


        for (int i = 0; i<n; i++)
        {
            cin>>a>>b;
            arr[a][b]++;
        }

        for (int i = 1; i<=16; i++)
            for (int j = i; j<=16; j++)
            {
                if(!arr[i][j]) continue;
                for (int k = 0; k<m; k+=j)
                {
                    result[k]+=arr[i][j];
                    result[k+i]-=arr[i][j];
                }
            }
        ans[ result[0] ]++;
        for (int i = 1; i<m; i++)
        {
            result[i]+=result[i-1];
            ans[ result[i] ]++;
        }

        for (int i =0; i<=n; i++)
            cout<<ans[i]<<"\n";
    }
    return 0;
}
