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


int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM

    int n;

    scanf("%d", &n);

    if(n<4) puts("NO");
    else
    {
        puts("YES");
        if(n%2==0)
        {
            puts("3 * 4 = 12");
            puts("12 * 2 = 24");
            puts("1 * 24 = 24");
            n-=4;
            for (int i = 0; i<n; i+=2)
            {
                printf("%d - %d = 1\n", i+6, i+5);
                puts("1 * 24 = 24");
            }
        }
        else
        {
            puts("3 - 1 = 2");
            puts("2 * 2 = 4");
            puts("5 * 4 = 20");
            puts("20 + 4 = 24");
            n-=5;
            for (int i = 0; i<n; i+=2)
            {
                printf("%d - %d = 1\n", i+7, i+6);
                puts("1 * 24 = 24");
            }
        }

    }




    return 0;
}
