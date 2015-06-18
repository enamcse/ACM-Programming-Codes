/**
* H:\Dropbox\Code\Codeforces\493C.cpp
*
* Created on: 2014-12-03-21.39.19, Wednesday
* Author: Enamul Hassan
* Verdict: SOLVED
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

vector< pair<int,int> >v;

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1, cnt1=0,cnt2=0;
    ll a,b, dif=-inf,x,y, point;
    _
    cin>>n;
    a=b=0;
    for (int i = 0; i<n; i++)
    {
        cin>>t;
        v.pb(make_pair(t,1));
    }
    cin>>m;

    for (int i = 0; i<m; i++)
    {
        cin>>t;
        v.pb(make_pair(t,2));
    }
    sort(all(v));
    t = v.size();
    x = n*3LL;
    y = m*3LL;
    if(x-y>dif)
    {
        a=x;
        b=y;
        dif = x-y;
    }
    else if(x-y==dif&&x>a)
    {
        a=x;
        b=y;
    }
    for (int i = 0; i<t-1; i++)
    {
        if(v[i].second==1) cnt1++;
        else  cnt2++;
        if(v[i].first==v[i+1].first) continue;
        x = ((n-cnt1)*3LL+cnt1*2LL);
        y = ((m-cnt2)*3LL+cnt2*2LL);
        if(x-y>dif)
        {
            a=x;
            b=y;
            dif = x-y;
        }
        else if(x-y==dif&&x>a)
        {
            a=x;
            b=y;
        }
    }
    if(v[t-1].second==1) cnt1++;
    else  cnt2++;
    x = ((n-cnt1)*3LL+cnt1*2LL);
    y = ((m-cnt2)*3LL+cnt2*2LL);
    if(x-y>dif)
    {
        a=x;
        b=y;
        dif = x-y;
    }
    else if(x-y==dif&&x>a)
    {
        a=x;
        b=y;
    }
    x = n*2LL;
    y = m*2LL;
    if(x-y>dif)
    {
        a=x;
        b=y;
        dif = x-y;
    }
    else if(x-y==dif&&x>a)
    {
        a=x;
        b=y;
    }
    cout<<a<<':'<<b<<endl;

    return 0;
}
