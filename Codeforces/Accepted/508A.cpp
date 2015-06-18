/**
* H:\Dropbox\Code\Codeforces\508A.cpp
* Created on: 2015-01-27-22.26.53, Tuesday
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

int arr[1005][1005];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1, x, y,k, z, a, b, c, la, lb,ma,mb;
    _

	cin>>n>>m>>k;

    for (x=1; x<=k; x++)
    {
        cin>>a>>b;
        arr[a][b] = 1;

        for (int i = a-1; i<=a; i++)
            for (int j = b-1; j<=b; j++)
            {
                bool flag = true;

                for (int s = i; s<i+2; s++)
                    for (int ss = j; ss<j+2; ss++)
                        if(arr[s][ss]==0) flag = false;

                if(flag)
                {

                    cout<<x;
                    for (x++; x<=k; x++)
                        cin>>a>>b;
                    return 0;
                }
            }


    }

    cout<<"0";
   return 0;
}
