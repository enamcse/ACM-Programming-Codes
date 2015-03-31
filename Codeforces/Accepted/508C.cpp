/**
* H:\Dropbox\Code\Codeforces\508C.cpp
* Created on: 2015-01-27-22.27.34, Tuesday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 2005
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

int w[sz], mom[sz];
bool jalan[sz];
int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m,r, cas=1, k, c=500;
    _

    cin>>m>>t>>r;

    for (int i = 0; i<m; i++)
    {
        cin>>k;
        w[k+c]++;
    }

    for (int i = 0; i<=1000; i++)
    {
        if(w[i])
        {
            while(mom[i]<r)
            {
                int j,lim = i-t;
                for (j = i-1; j>=lim; j--)
                    if(jalan[j]==false) break;
                if(j==lim-1)
                {
                    cout<<"-1";return 0;
                }
                jalan[j++]=1;
                lim=j+t;
                for (; j<lim; j++)
                    mom[j]++;
            }
        }
    }
    c=0;
    for (int i = 0; i<=1000; i++)
        if(jalan[i]) c++;
    cout<<c;

   return 0;
}
