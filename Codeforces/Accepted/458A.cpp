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
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1; while(ghat>0)  {if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;} return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const) { return bigmod(bivajok,vag_const-2, vag_const);}

using namespace std;

bool g[sz], h[sz];

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1;
    int flag = 0;
    char line[2][sz];

    scanf("%s %s", line[0], line[1]);

    int x, y, z;

    x = strlen(line[0]);
    y = strlen(line[1]);
    z = max(x,y);
    for (int i = 0, j = x-1; j>=0; j--, i++)
    {
        if(line[0][i]=='1')g[j]=true;
    }

    for (int i = 0, j = y-1; j>=0; j--, i++)
    {
        if(line[1][i]=='1')h[j]=true;
    }

    bool run = true;
    while(run)
    {
        run = false;
        for (int i = z; i>=2; i--)
        {
            while(i>=2&&!g[i]&&g[i-1]&&g[i-2])
            {
                run = true;
                g[i] = true;
                g[i-2] = g[i-1] = false;
                i+=2;
            }
            while(i>=2&&!h[i]&&h[i-1]&&h[i-2])
            {
                run = true;
                h[i] = true;
                h[i-2] = h[i-1] = false;
                i+=2;
            }
        }
    }


    for (int i = z+2; i>=0; i--)
    {
        if((g[i]^h[i]))
        {
            if(g[i]==true) flag = 1;
            else flag = 2;
            break;
        }
    }


    if(flag==1) printf(">");
    else if(flag==2) printf("<");
    else  printf("=");

    return 0;
}
