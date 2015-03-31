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

#define sz 50005
#define pb(a) push_back(a)
#define pp pop_back()
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

int main()
{
#ifdef ENAM
//    fread;
//    fwrite;
#endif // ENAM
    int t, n, m, cas=1;

    int x[4],  y[4], xx[4];
    bool flag = true;
    for (int i = 0; i<2 ; i++)
        scanf("%d %d", &x[i], &y[i]);

    if(x[0]== x[1])
    {
        n = y[1] - y[0];
        x[3] = x[2] = x[0] + n;
        y[2] = y[0];
        y[3] = y[1];
    }
    else if(y[0] == y[1])
    {
        n = x[1] - x[0];
        y[3] = y[2] = y[0] + n;
        x[2] = x[0];
        x[3] = x[1];
    }
    else if(x[0] > x[1] && y[0] > y[1])
    {
        x[2] = x[1];
        y[2] = y[0];

        x[3] = x[0];
        y[3] = y[1];
        xx[0] = (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]);
        xx[1] = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);
        xx[2] = (x[0] - x[3]) * (x[0] - x[3]) + (y[0] - y[3]) * (y[0] - y[3]);
        xx[3] = (x[1] - x[3]) * (x[1] - x[3]) + (y[1] - y[3]) * (y[1] - y[3]);
        if(!(xx[0]==xx[1] && xx[1] == xx[2] && xx[2] == xx[3])) flag = false;

    }
    else if(x[0] > x[1] && y[0] < y[1])
    {
        x[2] = x[0];
        y[2] = y[1];

        x[3] = x[1];
        y[3] = y[0];
        xx[0] = (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]);
        xx[1] = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);
        xx[2] = (x[0] - x[3]) * (x[0] - x[3]) + (y[0] - y[3]) * (y[0] - y[3]);
        xx[3] = (x[1] - x[3]) * (x[1] - x[3]) + (y[1] - y[3]) * (y[1] - y[3]);
        if(!(xx[0]==xx[1] && xx[1] == xx[2] && xx[2] == xx[3])) flag = false;

    }
    else if(x[0] < x[1] && y[0] > y[1])
    {
        x[2] = x[1];
        y[2] = y[0];

        x[3] = x[0];
        y[3] = y[1];
        xx[0] = (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]);
        xx[1] = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);
        xx[2] = (x[0] - x[3]) * (x[0] - x[3]) + (y[0] - y[3]) * (y[0] - y[3]);
        xx[3] = (x[1] - x[3]) * (x[1] - x[3]) + (y[1] - y[3]) * (y[1] - y[3]);
        if(!(xx[0]==xx[1] && xx[1] == xx[2] && xx[2] == xx[3])) flag = false;
    }
    else if(x[0] < x[1] && y[0] < y[1])
    {
        x[2] = x[0];
        y[2] = y[1];

        x[3] = x[1];
        y[3] = y[0];
        xx[0] = (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]);
        xx[1] = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);
        xx[2] = (x[0] - x[3]) * (x[0] - x[3]) + (y[0] - y[3]) * (y[0] - y[3]);
        xx[3] = (x[1] - x[3]) * (x[1] - x[3]) + (y[1] - y[3]) * (y[1] - y[3]);
        if(!(xx[0]==xx[1] && xx[1] == xx[2] && xx[2] == xx[3])) flag = false;
    }
    else {printf("-1"); return 0;}


     if(flag) printf("%d %d %d %d", x[2], y[2], x[3], y[3]);
    else printf("-1");





    return 0;
}
