//Verdict: NOT SOLVED
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

ll num[100][100] = {{5, 10, 10, 1, 6, 4, 3, 9, 6, 4},
{2, 10, 9, 4, 9, 5, 1, 10, 1, 5},
{1, 3, 7, 3, 10, 7, 5, 1, 7, 5},
{5, 1, 2, 7, 3, 2, 4, 2, 1, 3},
{7, 6, 6, 6, 4, 10, 5, 1, 5, 5},
{3, 1, 10, 5, 8, 1, 9, 10, 2, 7},
{1, 7, 1, 10, 5, 10, 5, 3, 3, 3},
{6, 3, 10, 2, 5, 1, 6, 7, 10, 9},
{1, 7, 9, 6, 2, 7, 10, 1, 9, 6},
{10, 9, 6, 10, 4, 7, 6, 3, 4, 7}};

//void rec(int pos, int sum)
//{
//    flag[sum]=true;
//    if(pos==v.size()) return;
//    rec(pos+1,sum+v[pos]);
//    rec(pos+1,sum);
//    return;
//}


int main()
{
    #ifdef ENAM
//        fread;
//    fwrite;
    #endif // ENAM
    double  sum=0,now=0;
    int n,m=0, cas=1;

    for (int i = 0; i<10; i++)
    {
        num[10][i]=1;
        for (int j = 0; j<10; j++)
            num[10][i]*=num[j][i];
        for (int j = 0; j<10; j++)
            num[i][10]+=num[i][j];
        num[10][10]+=num[10][i];
        num[10][11]+=num[i][10];
    }
    cout<<num[10][10]+num[10][11];

//    while(~scanf("%d, ", &n))
//    {
////        sum+=(n==15?20:n);
////        now+=n;
////        m++;
//        v.pb(n);
////        if(n!=1&&n%2) m++;
//    }
//    sort(allr(v));
//    now=v[0]+v[1]+v[2];
//    cout<<now/3.0<<' '<<now<<endl;
//
////    rec(0,0);
//
////    for (int i = 0; i<v.size(); i++)
////        if(flag[ v[i] ]) m++;
////    cout<<m;

    return 0;
}

