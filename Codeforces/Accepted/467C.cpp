//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include <set>
#include <string>
#include <stack>
#include <bitset>

#define sz 50005
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const)
{
    ll vag_shesh=1;
    while(ghat>0)
    {
        if(ghat%2==1)
        {
            vag_shesh=(vag_shesh*sonkha)%vag_const;
        }
        ghat/=2;
        sonkha=(sonkha*sonkha)%vag_const;
    }
    return vag_shesh;
}
ll inverse_mod(ll bivajok, ll vag_const)
{
    return bigmod(bivajok,vag_const-2, vag_const);
}

using namespace std;

int n,m,k,arr[5010];
ll cumsum[5010];
ll dp[5010][5010];

ll rec(int start, int cnt)
{
//    cout<<start<<" : "<<cnt<<endl;
    if(!cnt) return 0;
    if(start>=n) return -100000000000000000LL;
    ll &ret = dp[start][cnt];
    if(ret!=-1LL) return ret;

    ret = -100000000000000000LL;

    if(start+1<n)ret=max(ret,rec(start+1,cnt));
    if(start+m<=n)ret=max(ret,rec(start+m,cnt-1)+ cumsum[start+m]-cumsum[start]);
//            cout<<m<<" L: "<<i<<" : "<<ret<<" > "<<cumsum[i+m]<<" :: "<<cumsum[i]<<endl;


    return ret;
}



int main()
{
#ifdef ENAM
    	fread;
//	fwrite;
#endif // ENAM


    clr(dp,-1LL);

    scanf("%d %d %d", &n,&m, &k);

    for (int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        cumsum[i+1]=arr[i];
        if(i)cumsum[i+1]+=cumsum[i];
    }

    printf("%I64d",rec(0,k));



    return 0;
}

