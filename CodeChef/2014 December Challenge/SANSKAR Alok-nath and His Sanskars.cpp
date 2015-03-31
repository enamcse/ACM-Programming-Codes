/**
* H:\Dropbox\Code\CodeChef\2014 December Challenge\SANSKAR Alok-nath and His Sanskars.cpp
*
* Created on: 2014-12-09-16.32.53, Tuesday
* Author: Enamul Hassan
* Verdict: NOT SOLVED
**/

#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);

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
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int last, n, k;
ll arr[50], avg, alloc[10];

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t;
    ll sum, mx;

    scanf("%d", &t);

    while(t--)
    {
        mx = sum = 0;
        clr(alloc,0);
        scanf("%d %d", &n, &k);
        assert(n<=21);
        assert(k<=8);
        for (int i = 0; i<n; i++)
        {
            scanf("%lld", &arr[i]);
            sum+=arr[i];
            mx = max(mx,arr[i]);
        }
        avg = sum/k;
        if(sum%k||mx>avg)
        {
            puts("no");
            continue;
        }

        sort(arr,arr+n);
        reverse(arr,arr+n);

        flag = false;

        for (int i = 0; i<; )
            ;

        if(flag)puts("yes");
        else puts("no");
    }
    return 0;
}
