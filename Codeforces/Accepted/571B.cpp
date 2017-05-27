/**
* H:\Dropbox\Code\Codeforces\571B.cpp
* Created on: 2015-08-22-23.36.39, Saturday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 300005
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e17)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define cspf printf("Case %d:", cas++);
#define csco cout<<"Case "<<cas++<<":";
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int A[sz],c;
ll dp[5005][5005];
ll rec(int pos, int ex, int ind)
{
    if(pos==0)
    {
        if(ex==0) return 0;
        return inf;
    }
    ll &ret = dp[pos][ex];
    if(~ret) return ret;
    ret = rec(pos-1,ex,ind+c) + A[ind+c-1]-A[ind];
    ret = min(ret,rec(pos-1,ex-1,ind+c+1) + A[ind+c]-A[ind]);
    return ret;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,k;
//    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    scanf("%d %d",&n,&k);

    for (int i = 0; i<n; i++)
        scanf("%d", &A[i]);

    sort(A,A+n);

    c = n/k;
    clr(dp,-1);
    printf("%I64d",rec(k,n%k,0));

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
