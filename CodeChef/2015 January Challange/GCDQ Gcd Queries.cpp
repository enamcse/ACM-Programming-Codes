/**
* H:\Dropbox\Code\CodeChef\2015 January Challange\GCDQ Gcd Queries.cpp
* Created on: 2015-01-05-21.08.24, Monday
* Verdict: Not Solved
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

int stree[sz<<2];

void build(int ind, int LB, int UB, int P, int val)
{
    if(P<LB||P>UB) return;
    if(LB == UB && P == LB)
    {
        stree[ind] = val;
        return;
    }
    int mid = ((LB+UB)>>1), m = (ind<<1);
    if(P<=mid) build(m, LB,mid, P, val);
    else build(m+1, mid+1, UB, P, val);
    stree[ind] = __gcd(stree[m], stree[m+1]);
    return;
}

int query(int ind, int LB, int UB, int L, int U)
{
    if(U<LB||L>UB) return 0;
    if(UB==LB) return stree[ind];

    int mid = ((LB+UB)>>1), m = (ind<<1), k, ret=0;
    if(L<=LB&&UB<=U) return stree[ind];
    return __gcd(query(m,LB,mid,L,U), query(m+1,mid+1,UB,L,U));
}





int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,q, l, r, ans;
    _

	cin>>t;


	while(t--)
    {
        cin>>n>>q;
        for (int i = 0; i<n; i++)
        {
            cin>>m;
            build(1,1,n,i+1,m);
        }

        for (int i = 0; i<q; i++)
        {
            cin>>l>>r;
            if(l==1) ans = query(1,1,n,r+1,n);
            else if(r==n) ans = query(1,1,n,1,l-1);
            else ans = __gcd(query(1,1,n,1,l-1),query(1,1,n,r+1,n));
            cout<<ans<<"\n";
        }

    }




   return 0;
}
