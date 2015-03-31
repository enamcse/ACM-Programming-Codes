/**
* H:\Dropbox\Code\CodeChef\2014 November Challange\POWERMUL Fombinatorial.cpp
*
* Created on: 2014-11-08-06.17.57, Saturday
* Author: Enamul Hassan
* Verdict: NOT SOLVED
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100105
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

ll prime[sz], factors[sz], ans[sz];
bool siv[sz];
ll mod,cnt=1;
ll stree[sz<<2];
map<ll,int>mpp;
void build(int ind, int LB, int UB, int P)
{
    if(P<LB||P>UB) return;
    if(LB == UB)
    {
        stree[ind] = 1;
        return;
    }
    int mid = ((LB+UB)>>1), m = (ind<<1);
    if(P<=mid) build(m, LB,mid, P);
    else build(m+1, mid+1, UB, P);
    stree[ind] = stree[m] * stree[m+1];
    return;
}

void update(int ind, int LB, int UB, int P)
{
    if(UB==LB)
    {
        stree[ind] = bigmod(prime[P],factors[P],mod);
        return;
    }
    int mid = ((LB+UB)>>1), m = (ind<<1);
    if(P<=mid) update(m, LB,mid, P);
    else update(m+1, mid+1, UB, P);
    stree[ind] = (stree[m] * stree[m+1])%mod;
    return;
}

void factorizeN(int n)
{
    clr(factors,0);

    for (int i = 1; i<cnt; i++)
        build(1,1,cnt-1,i);


    set<int>use;
    ll num, now, cntn;
    int lim = (n>>1);
    for (int i = 0; i<lim; i++)
    {
        use.clear();
        num=now = n-i;
        int sq = sqrt(now);
        for (int j = 1; prime[j]<=sq; j++)
        {
            if(now%prime[j]==0)
            {
                cntn=0;
                while(now%prime[j]==0) cntn++,now/=prime[j];
                factors[ j ]+=(num*cntn);
                use.insert(j);
            }
        }
        if(now>1){
            factors[ mpp[now] ]+=num;
            use.insert(mpp[now]);
        }
        num=now = i+1;
        sq = sqrt(now);
        for (int j = 1; prime[j]<=now; j++)
        {
            if(now%prime[j]==0)
            {
                cntn=0;
                while(now%prime[j]==0) cntn++,now/=prime[j];
                factors[ j ]-=(num*cntn);
                use.insert(j);
            }
        }
        if(now>1){
            factors[ mpp[now] ]+=num;
            use.insert(mpp[now]);
        }

        for (set<int>::iterator it = use.begin(); it!=use.end(); it++)
                update(1,1,cnt-1,*it);
        ans[i]=stree[1]%mod;
    }
    return;
}

void sieve(int n)
{
    int sq = sqrt(n);
    for (int i = 3; i<=sq; i+=2)
        if(!siv[i])
            for (int j = i*i; j<=n; j+=i+i)
                siv[j]=true;

    prime[cnt++]=2;
    for (int i = 3; i<=n; i+=2)
        if(!siv[i]) prime[cnt++]=i;

    for (int i = 1; i<cnt; i++)
        mpp[ prime[i] ]=i;

    return;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
//    _
    sieve(sz);
//    cout<<cnt<<endl;
    ll t, n, m, q,x,y;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld %lld", &n,&mod,&q);
        factorizeN(n);
        for (int i = 0; i<q; i++)
        {
            scanf("%lld", &x);
//            for (int j = 0; j<10; j++)printf("%d = %lld\n",j, ans[j]);
            printf("%lld\n", ans[min(x,n-x)-1]);
        }
    }
    return 0;
}
