/**
* H:\Dropbox\Code\CodeChef\2014 October Cook off\ANUMLA Mahesh and his lost array.cpp
*
* Created on: 2014-10-19-22.06.45, Sunday
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

map<int,int>mp;
int ans[20],cnt,now;
int arr[(1<<15)];
int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, ind,z, k;

    scanf("%d", &t);

    while(t--)
    {
        mp.clear();
        scanf("%d", &n);
        cnt=now=0;
        m = (1<<n);
        for (int i=0; i<m; i++)
        {
            scanf("%d", &z);
            mp[z]++;
        }
        map<int,int>::iterator it = mp.begin();


        for (it++; it!=mp.end(); it++)
        {
            while(it->second)
            {
                k = it->first;
                ans[cnt++]=k;
                z = now;
                arr[now++]=k;
                 mp[ k ]--;
                for (int i = 0; i<z; i++)
                {
                        mp[ arr[i]+k ]--;
                        arr[ now++ ]=arr[i]+k;
                }
            }
            if(cnt==n) break;
        }

//        for (int i = z; i<m; i+=z)
//        {
//            ans[cnt++]=i;
//            if(cnt==n) break;
//        }

        for (int i = 0; i<n; i++)
        {
            if(i)printf(" ");
            printf("%d", ans[i]);
        }
        puts("");
    }



    return 0;
}
