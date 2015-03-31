/**
* H:\Dropbox\Code\Codeforces\500B.cpp
* Created on: 2014-12-30-20.56.38, Tuesday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 305
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

int arr[sz],ans[sz];
int mat[sz][sz];
bool flag[sz], ok[sz];


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _
	char ch;
	cin>>n;

	for (int i = 0; i<n; i++)
	    cin>>arr[i];

    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
        {
            cin>>ch;
            if(ch=='1')mat[i][j]=1;
        }

    for (int k = 0; k<n; k++)
        for (int i = 0; i<n; i++)
            for (int j = 0; j<n; j++)
                mat[i][j]|=(mat[i][k]&mat[k][j]);

    for (int i = 0; i<n; i++)
    {
        int now = inf, ind=-1,j;
        for (j = 0; j<n; j++)
        {
            if(!flag[j])
            {
                if(arr[j]<now)
                {
                    ind = j;
                    now = arr[j];
                }
            }
        }

        for (j = 0; j<n; j++)
        {
            if(!ok[j]&&(mat[ind][j]|mat[j][ind]))
            {
                ok[j] = 1;
                ans[j] = arr[ind];
                flag[ind]=1;
                break;
            }
        }

        if(j==n)
        {
            ok[ind] = 1;
            flag[ind]=1;
            ans[ind] = arr[ind];
        }

    }

	for (int i = 0; i<n; i++)
	    cout<<ans[i]<<" ";



   return 0;
}
