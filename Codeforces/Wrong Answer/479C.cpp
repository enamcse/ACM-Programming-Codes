/**
* H:\Dropbox\Code\Codeforces\479C.cpp
*
* Created on: 2014-10-19-19.13.52, Sunday
* Author: Enamul Hassan
* Verdict: NOT SOLVED
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

vector< pair<int,int> >v;

bool comp(const pair<int,int> &a, const pair<int,int> &b)
{
    return min(a.first,a.second)<min(b.first,b.second);
}

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, a,b;

    scanf("%d", &n);
    t=0;
    for (int i = 0; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        v.pb(make_pair(a,b));
    }
    sort(all(v));
    bool flag = true;
    for (int i = 1; i<n; i++)
        if(t==0)
        {
            if(v[i].second<v[i-1].second)
                if(v[i].first<v[i-1].second){flag = false; break;}
                else t=1;
        }
        else
        {
            if (v[i].second<v[i-1].first)
            {
                if (v[i].first<v[i-1].first) {flag = false; break;}
            }
            else t = 0;
        }


    for (int i = 0; i<n; i++)
        cout<<v[i].first<<':'<<v[i].second<<endl;


    if(flag) printf("%d",v[n-1].second);
    else printf("%d",v[n-1].first);

    return 0;
}
