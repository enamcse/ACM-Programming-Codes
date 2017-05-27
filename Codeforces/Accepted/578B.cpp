/**
* H:\Dropbox\Code\Codeforces\578B.cpp
* Created on: 2015-09-16-21.35.56, Wednesday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ(a) ((int)a.size())
#define sz 200005
#define pb push_back
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define cntbit(mask) __builtin_popcount(mask)
#define unify(a) stable_sort(a.begin(),a.end());a.resize(distance(a.begin(),unique(all(a))));
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e18)
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

ll arr[sz],res,stree[sz<<2],now,kk;

void build(int ind, int LB, int UB, int P,int val)
{
    if(P<LB||P>UB) return;
    if(LB == UB)
    {
        stree[ind] = val;
        return;
    }
    int mid = ((LB+UB)>>1), m = (ind<<1);
    if(P<=mid) build(m, LB,mid, P,val);
    else build(m+1, mid+1, UB, P,val);
    stree[ind] = stree[m] | stree[m+1];
    return;
}

//void query(int ind, int LB, int UB, int P)
//{
//    if(UB==LB)
//    {
//        update(1,1,total,UB,0);
//        printf("%d\n", tree[UB-1]);
//        return;
//    }
//    int mid = ((LB+UB)>>1), m = (ind<<1), k;
//    k = P - stree[m];
//    if(k<=0) query(m, LB,mid, P);
//    else query(m+1, mid+1, UB, k);
//    return;
//}

ll query(int ind, int LB, int UB, int P, int Q)
{
    if(LB>Q||UB<P) return 0L;
    if(LB>=P&&UB<=Q) return stree[ind];
    int mid = ((UB+LB)>>1);
    return ((query((ind<<1), LB, mid, P, Q)|query((ind<<1)+1,mid+1, UB, P,Q)));
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    ll t, n, m,k,x, cas=1,ind=0;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n>>k>>x;

    for (int i = 0; i<n; i++)
    {
        cin>>arr[i];
        build(1,1,n,i+1,arr[i]);
    }

    for (int i = 0; i<n; i++)
    {
        now = query(1,1,n,1,i)|query(1,1,n,i+2,n);
        kk = arr[i];
        for (int i = 0; i<k; i++)
        kk*=x;
        res = max(res,now|kk);
    }

    cout<<res;

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
