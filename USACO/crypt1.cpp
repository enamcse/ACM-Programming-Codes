/*
ID: manetsus
PROG: crypt1
LANG: C++
*/

/**
* H:\Dropbox\Code\USACO\crypt1.cpp
*
* Created on: 2014-11-28-03.41.46, Friday
* Author: Enamul Hassan
* Verdict: SOLVED
**/

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
#define sz 100
#define input_file "crypt1.in"
#define output_file "crypt1.out"
#define pb(a) push_back(a)
#define pp pop_back
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen(input_file,"r",stdin)
#define fwrite freopen(output_file,"w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define chng(a,b) a^=b^=a^=b;
#define PI acos(-1)
#define mod 1000000007
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}
using namespace std;

bool arr[10];
vector<int>v;
int cnt;
bool check()
{
    int a = v[0]*100+v[1]*10+v[2];
    int b = a*v[3];
    int c = a*v[4];
    int d = b+c*10;
    if(b>999||c>999||d>9999) return false;
    int p = b;
    while(p)
    {
        if(!arr[p%10]) return false;
        p/=10;
    }
    p = c;
    while(p)
    {
        if(!arr[p%10]) return false;
        p/=10;
    }
    p = d;
    while(p)
    {
        if(!arr[p%10]) return false;
        p/=10;
    }
    return true;
}


void rec(int pos)
{
    if(pos==5)
    {
        if(check()) cnt++;
        return;
    }
    for (int i = 0; i<10; i++)
        if(arr[i])
        {
            v.pb(i);
            rec(pos+1);
            v.pp();
        }
    return;
}


int main()
{
    #if !defined ENAM
        fread;
    fwrite;
    #endif // ENAM

    int n, m;

    cin>>n;

    for (int i = 0; i<n; i++)
    {
        cin>>m;
        arr[m]=true;
    }

    rec(0);
    cout<<cnt<<endl;

    return 0;
}
