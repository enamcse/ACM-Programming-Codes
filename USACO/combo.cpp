/*
ID: manetsus
PROG: combo
LANG: C++
*/

/**
* H:\Dropbox\Code\USACO\combo.cpp
*
* Created on: 2014-11-28-04.31.12, Friday
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

#define sz 100
#define input_file "combo.in"
#define output_file "combo.out"
#define pb(a) push_back(a)
#define pp pop_back
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen(input_file,"r",stdin)
#define fwrite freopen(output_file,"w",stdout)
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

set< pair<int,pair<int,int> > >s;

int a[3], b[3], know[3],n;

void reca(int pos)
{
    if(pos == 3)
    {
        s.insert(make_pair(know[0], make_pair(know[1], know[2])));
        return;
    }

    int k = a[pos]-2;
    if(k<1) k = n+k;
    if(n==1)k=1;
    for (int i = 0; i<5; i++)
    {
        know[pos] = k;
        reca(pos+1);
        k++;
        if(k>n) k =1;
    }
}


void recb(int pos)
{
    if(pos == 3)
    {
        s.insert(make_pair(know[0], make_pair(know[1], know[2])));
        return;
    }

    int k = b[pos]-2;
    if(k<1) k = n+k;
    if(n==1)k=1;
    for (int i = 0; i<5; i++)
    {
        know[pos] = k;
        recb(pos+1);
        k++;
        if(k>n) k =1;
    }
}

int main()
{
    #if !defined ENAM
        fread;
        fwrite;
    #endif // ENAM

    cin>>n;

    for (int i = 0; i<3; i++)
        cin>>a[i];
    for (int i = 0; i<3; i++)
        cin>>b[i];

    reca(0);
    recb(0);

    cout<<s.size()<<endl;

    return 0;
}

