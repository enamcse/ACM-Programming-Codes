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

struct point
{
    int a,b;
    point(int x, int y)
    {
        a=x,b=y;
    }
};


vector<point>v;

bool comp(const point &x, const point &y)
{
    return x.b<y.b;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1, st, p, q=-1;
    int flag = 0;
    scanf("%d",&n);

    for (int i =0; i<n; i++)
    {
        scanf("%d",&m);
        v.pb(point(i+1,m));
    }

    sort(v.begin() ,v.end(), comp);

    if(v[0].a!=1) p = 1, flag = 1;
    else p =-1;
    for (int i = 1; i<n; i++)
    {
        if(flag==0||flag==2)
        {
            if(v[i].b==v[i-1].b) flag = 3;
            else if(v[i].a!=v[i-1].a+1)
            {
                if(p==-1)
                {
                    p = i+1;
                    flag = 1;
                }
                else flag = 3;
            }
        }
        else if(flag==1)
        {
            if(v[i].b==v[i-1].b) flag = 3;
            else if(v[i].a!=v[i-1].a-1)
            {
                if(q==-1)
                {
                    q = i;
                    flag = 2;
                }
                else flag = 3;
            }
        }
    }
    if(flag == 0)
    {
        printf("yes\n1 1\n");
    }
    else if(flag == 1){
        printf("yes\n%d %d\n", p, n);
    }
    else if(flag ==2){
        printf("yes\n%d %d\n", p, q);
    }
    else printf("no\n");

    return 0;
}
