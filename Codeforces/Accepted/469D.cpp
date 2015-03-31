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

struct node
{
    int pos;
    bool flag;

};

map<int,node>mp, mk;

int flag[sz];

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int a,b, t, n, m, x, cas=1;
    bool ase = true;
    node now;
    now.flag = true;
    scanf("%d %d %d", &n,&a,&b);

    for (int i = 0; i<n; i++)
    {
        scanf("%d", &x);
        now.pos = i;
        mp[ x ] = now;
    }
    mk = mp;
    for (map<int,node>:: iterator it= mp.begin(); it!=mp.end(); it++)
    {
        if(it->second.flag)
        {
            if(mp [a - it->first].flag)
            {
                flag[it->second.pos] = 0;
                flag[ mp[a - it->first].pos] = 0;
                mp [it->first].flag = false;
                mp [a - it->first].flag = false;
            }
            else if (mp [b - it->first].flag)
            {
                flag[it->second.pos] = 1;
                flag[ mp[b - it->first].pos] = 1;
                mp [it->first].flag = false;
                mp [b - it->first].flag = false;
            }
            else
            {
                ase = false;
                break;
            }
        }
    }

    if(ase)
    {
        puts("YES");
        for (int i = 0; i<n; i++)
            printf("%d ", flag[i]);
    }
    else
    {
        ase = true;

        for (map<int,node>:: iterator it= mk.begin(); it!=mk.end(); it++)
        {
            if(it->second.flag)
            {
                if (mk [b - it->first].flag)
                {
                    flag[it->second.pos] = 1;
                    flag[ mk[b - it->first].pos] = 1;
                    mk [it->first].flag = false;
                    mk [b - it->first].flag = false;
                }
                else if(mk [a - it->first].flag)
                {
                    flag[it->second.pos] = 0;
                    flag[ mk[a - it->first].pos] = 0;
                    mk [it->first].flag = false;
                    mk [a - it->first].flag = false;
                }
                else
                {
                    ase = false;
                    break;
                }
            }
        }

        if(ase)
        {
            puts("YES");
            for (int i = 0; i<n; i++)
                printf("%d ", flag[i]);
        }
        else puts("NO");


    }




    return 0;
}
