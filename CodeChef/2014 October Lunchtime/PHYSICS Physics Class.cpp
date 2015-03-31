/**
* H:\Dropbox\Code\CodeChef\2014 October Lunchtime\PHYSICS Physics Class.cpp
*
* Created on: 2014-10-26-13.21.27, Sunday
* Author: Enamul Hassan
* Verdict: NOT SOLVED++
**/

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

#define sz 100005
#define pb(a) push_back(a)
#define pp pop_back()
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
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
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

ll ans,cnt;
int n,F,t;
vector<int>v;


ll work(int now)
{
    ll d = F, q,r,c=0;
    while(d<=v[now])
    {
        q = v[now]/F;
        r = v[now]%F;
        if(!r) c+=binary_search(all(v),q);
        d*=F;
    }
    return c;
}


int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int now;
    scanf("%d", &t);


    while(t--)
    {
        scanf("%d %d", &n, &F);
        ans = 0;
        cnt=0;
        v.clear();
        for (int i = 0; i<n; i++)
        {
            scanf("%d", &now);
            v.pb(now);
        }

        sort(all(v));
        for (int i = 1; i<n; i++)
        {
            if(v[i]==v[i-1]) cnt++;
            else
            {
                ll pew=work(i-1);
                if(cnt)
                {
                    ll temp = cnt+1;
                    pew*=temp;
                    if(temp&1) cnt/=2;
                    else temp/=2;
                    ans+=cnt*temp+pew;
                    cnt=0;
                }
                else ans+=pew;
            }
        }
        ll pew=work(n-1);
        if(cnt)
        {

            ll temp = cnt+1;
            pew*=temp;
            if(temp&1) cnt/=2;
            else temp/=2;
            ans+=cnt*temp+pew;
            cnt=0;

        }

        printf("%lld\n", ans);
    }


    return 0;
}
