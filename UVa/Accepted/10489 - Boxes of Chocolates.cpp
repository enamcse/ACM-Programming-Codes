/**
* H:\Dropbox\Code\UVa\10489 - Boxes of Chocolates.cpp
*
* Created on: 2014-12-12-12.41.14, Friday
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
#define pi 3.14159265358979323846264338327950288419716939937510
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1,b, k, now;
    ll res, gun;
    scanf("%d", &t);

    while(t--)
    {
        res = 0;
        scanf("%d %d", &n, &b);
        for (int i = 0; i<b; i++)
        {
            scanf("%d", &k);
            gun = 1;
            for (int j = 0; j<k; j++)
            {
                scanf("%d", &now);
                gun*=now;
                gun%=n;
            }
            res+=gun;
            res%=n;
        }
        printf("%lld\n", res);
    }




    return 0;
}
