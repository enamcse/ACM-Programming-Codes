/**
* H:\Dropbox\Code\Codeforces\479B.cpp
*
* Created on: 2014-10-19-20.30.08, Sunday
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

int arr[200];

struct node{
    int dif, a, b;
    node(){}
    node(int x, int y)
    {
        a = x;
        b = y;
        dif = abs(arr[a]-arr[b]);
    }
};

bool comp(const node &a, const node &b)
{
    return a.dif<b.dif;
}

vector<node>v;
vector< pair<int,int> >ans;

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1, k,s;

    scanf("%d %d", &n, &k);

    for (int i = 0; i<n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i<k; i++)
    {
        v.clear();
        for (int j = 0; j<n; j++)
            for (int o = j+1; o<n; o++)
                v.pb(node(j,o));
        sort(all(v),comp);
        if(v[0].dif==0) break;

        if(v[0].a>v[0].b)
        {
            arr[ v[0].a ]--;
            arr[ v[0].b ]++;
            ans.pb(make_pair(v[0].a, v[0].b));
        }
        else
        {
            arr[ v[0].a ]++;
            arr[ v[0].b ]--;
            ans.pb(make_pair(v[0].b,v[0].a));
        }
    }

    return 0;
}
