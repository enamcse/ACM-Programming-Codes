/**
* H:\Dropbox\Code\UVa\12802 - Gift From the Gods.cpp
* Created on: 2015-01-25-17.04.47, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1000105
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
 bool siv[1000105];

 void seive()
 {
     int sq = sqrt(sz);

     for (int i = 3; i<=sq; i+=2)
         if(!siv[i])
            for (int j = i*i; j<sz; j+=i+i)
                siv[j] = true;
 }

bool pal_check(int n)
{
    vector<int>v;
    while(n)
    {
        v.pb(n%10);
        n/=10;
    }
    int k = v.size(), kk;
    kk = k/2;
    for (int i = 0; i<kk; i++)
        if(v[i] != v[k - i - 1]) return false;
    return true;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    _

    seive();

    while(cin>>n)
    {
        if(n==2||n%2)
           {
               if(!siv[n]&&pal_check(n)){
               cout<<n*2<<"\n";return 0;}
           }
        cout<<n*2<<"\n";
    }

   return 0;
}
