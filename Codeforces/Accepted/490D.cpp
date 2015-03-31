/**
* H:\Dropbox\Code\Codeforces\490D.cpp
*
* Created on: 2014-11-23-16.54.27, Sunday
* Author: Enamul Hassan
* Verdict: NOT SOLVED
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e19)
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

ll a[2],b[2],ans[4],mn=inf;

map<ll,pair<ll,pair<ll,ll> > >mpp[2];

set< pair<ll,ll> >flag[2];

void rec(ll a, ll b, ll val, bool op)
{
//    cout<<a<<"LL"<<b<<" "<<op<<" : "<<a*b<<endl;
    if(a>b) swap(a,b);
    if(flag[op].find(make_pair(a,b))!=flag[op].end()) return;

    flag[op].insert(make_pair(a,b));
    if(mpp[op].find(a*b)==mpp[op].end()) mpp[op][ a*b ] = make_pair(val, make_pair(a,b));
    if(a%2==0) rec(a/2,b,val+1,op);
    if(b%2==0) rec(a,b/2,val+1,op);
    if(a%3==0) rec(2*(a/3),b,val+1,op);
    if(b%3==0) rec(a,2*(b/3),val+1,op);

    return;
}


int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    _
    int t, n, m, cas=1;

    for (int i = 0; i<2; i++)
        cin>>a[i]>>b[i];

    rec(a[0],b[0],0,0);
    rec(a[1],b[1],0,1);

    for (map<ll,pair<ll,pair<ll,ll> > >::iterator it = mpp[0].begin(); it!=mpp[0].end(); it++)
    {
        if(mpp[1].find(it->first)!=mpp[1].end())
        {
            if(mpp[0][it->first].first+mpp[1][it->first].first<mn)
            {

                mn = mpp[0][it->first].first+mpp[1][it->first].first;
                ans[0]=mpp[0][it->first].second.first;
                ans[2]=mpp[1][it->first].second.first;
                ans[1]=mpp[0][it->first].second.second;
                ans[3]=mpp[1][it->first].second.second;
            }
        }
    }



    if(mn>=(ll)inf) {cout<<-1<<"\n";return 0;}

    cout<<mn<<"\n";

    for (int i = 0; i<2; i++)
        cout<<ans[i*2]<<' '<<ans[i*2+1]<<'\n';



    return 0;
}
