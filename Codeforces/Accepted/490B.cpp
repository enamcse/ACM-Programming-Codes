/**
* H:\Dropbox\Code\Codeforces\490B.cpp
*
* Created on: 2014-11-23-15.00.15, Sunday
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

int ans[sz], cnt[sz*10];

map<int,int>aa,bb;

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    _
    int t, n, m, cas=1,st=2,en, x, y;

    cin>>n;
    en = n-3;
    for (int i = 0; i<n; i++)
    {
        cin>>x>>y;
        aa[ x ] = y;
        bb[ y ] = x;
        cnt[ x ]++;
        cnt[ y ]++;
    }

    for (map<int,int>::iterator it = aa.begin(); it!=aa.end(); it++)
    {
        if(cnt[(it->first)]==1)
        {
            ans[0] = it->first;
        }
        if((it->first)==0)
        {
            ans[1] = it->second;
        }
    }


    for (map<int,int>::iterator it = bb.begin(); it!=bb.end(); it++)
    {
        if(cnt[(it->first)]==1)
        {
            ans[n-1] = it->first;
        }
        if((it->first)==0)
        {
            ans[n-2] = it->second;
        }
    }

    while(st<=en)
    {
//        for (int i =0; i<n; i++)
//        cout<<ans[i]<<'H';cout<<endl;

        ans[st] = aa[ ans[st-2] ];
//        ans[en] = aa[ ans[en+1] ];
        st++;
//        en--;
    }

    for (int i =0; i<n; i++)
        cout<<ans[i]<<' ';



    return 0;
}
/*
7
0 999
100 109
999 533
109 411
533 21
411 3
21 0
*/
