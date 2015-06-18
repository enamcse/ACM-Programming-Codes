/**
* H:\Dropbox\Code\Codeforces\479D.cpp
*
* Created on: 2014-10-19-16.54.46, Sunday
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

int arr[sz];

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1,l,x,y, ans = 2, a, b;

    scanf("%d %d %d %d", &n, &l, &x, &y);

    for (int i = 0; i<n; i++)
        scanf("%d", &arr[i]);

    sort(arr,arr+n);


    bool f1,f2;
    f1=f2=false;
    for (int i = 0; i<n; i++)
    {
        if(binary_search(arr, arr+n, arr[i]+x) || binary_search(arr, arr+n, arr[i]-x)) f1=true;
        if(binary_search(arr, arr+n, arr[i]+y) || binary_search(arr, arr+n, arr[i]-y)) f2=true;
        if(f1&&f2) break;
    }

    if(f1&&f2) ans = 0;
    else if(f1||f2)
    {
        ans = 1;
        if(f1) a = y;
        if(f2) a = x;
    }
    else
    {
        ans =2;
        a=x;b=y;
    }




    if(ans>1)
    {
        for (int i =0; i<n; i++)
        {
            if(arr[i]-x>=0 && binary_search(arr, arr+n, arr[i]-x+y)){a =arr[i]-x; ans=1;break;}
            if(arr[i]-y>=0 && binary_search(arr, arr+n, arr[i]+x-y)){a = arr[i]-y; ans=1;break;}
            if(arr[i]+x<=l && binary_search(arr, arr+n, arr[i]+x-y)){a =arr[i]+x; ans=1;break;}
            if(arr[i]+y<=l && binary_search(arr, arr+n, arr[i]-x+y)){a = arr[i]+y; ans=1;break;}
            if(arr[i]-x>=0 && binary_search(arr, arr+n, arr[i]-x-y)){a =arr[i]-x; ans=1;break;}
            if(arr[i]-y>=0 && binary_search(arr, arr+n, arr[i]+x+y)){a = arr[i]-y; ans=1;break;}
            if(arr[i]+x<=l && binary_search(arr, arr+n, arr[i]+x+y)){a =arr[i]+x; ans=1;break;}
            if(arr[i]+y<=l && binary_search(arr, arr+n, arr[i]-x-y)){a = arr[i]+y; ans=1;break;}
//            i+=max(0,n-2);
        }

    }

    printf("%d\n", ans);
    if(ans==1) printf("%d", a);
    else if(ans==2) printf("%d %d", a, b);

    return 0;
}
