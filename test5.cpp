/**
* H:\Dropbox\Code\test5.cpp
* Created on: 2015-02-17-00.24.39, Tuesday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 2000005
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
//const int maxd = sz-1;
//vector<int>facts[sz];
//int divisors[sz];
//
//
//void factorize(int x)
//{
//    int k = facts[x].size();
//
//    for (int i = 0; i<k; i++)
//    {
//
//    }
//
//}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,i,j;
    _

    long double kk = 9.988;
    scanf("%Lf", &kk);
    printf("%Lf", kk);
//	// Generates the divisors
//    for(i=2;i<=maxd;i++) if(facts[i].size()==0)
//        for(j=i;j<=maxd;j+=i) facts[j].pb(i);
//     n=1000001;
// //    for (int i = 2; i<n; i++)
// //    {
// //        factorize(i);
// //    }
// //

//     m = 0;t=0;
//     for (int i = 2; i<n; i++)
//     {
//         int cnt = 0;
//         for (int j = 1; j<=i/j; j++)
//         {
//             if(i%j==0) cnt+=2;
//             if(j==i/j) cnt--;
//         }
// //        cnt-=2;
//         if(cnt&1) m++;
//         t = max(t,cnt);
//     }
//     cout<<m<<" "<<t<<endl;

   return 0;
}
