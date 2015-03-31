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
//    	fread;
//	fwrite;
#endif // ENAM
    ll n, d1, d2, t1, t2, t3,k,m, mx;
    int t;
    scanf("%d", &t);
    bool flag;
    while(t--)
    {
        flag = false;
        scanf("%I64d %I64d %I64d %I64d", &n, &k, &d1, &d2);
        if(n%3)
        {
            printf("no\n");
        }
        else
        {
            m = n - k;
            //case 1
            t2 = k+d2-d1;
            if(!(t2%3))
            {
                t2/=3;

                t3 = t2 - d2;
                t1 = d1 + t2;
                mx = max(t1, max(t2,t3));
                mx = mx+mx+mx - t1-t2-t3;
                if(m>=mx&&t1>=0&&t2>=0&&t3>=0) flag = true;
            }
            //case 2
            t2 = k+d2+d1;
            if(!(t2%3))
            {
                t2/=3;
                t3 = t2 - d2;
                t1 = t2 - d1;
                mx = max(t1, max(t2,t3));
                mx = mx+mx+mx - t1-t2-t3;
                if(m>=mx&&t1>=0&&t2>=0&&t3>=0) flag = true;
            }
            //case 3
            t2 = k-d1-d2;
            if(!(t2%3))
            {
                t2/=3;

                t3 = t2 + d2;
                t1 = d1 + t2;
                mx = max(t1, max(t2,t3));
                mx = mx+mx+mx - t1-t2-t3;
                if(m>=mx&&t1>=0&&t2>=0&&t3>=0) flag = true;
            }
            //case 4
            t2 = k-d2+d1;
            if(!(t2%3))
            {
                t2/=3;
                t3 = t2 + d2;
                t1 = t2 - d1;
                mx = max(t1, max(t2,t3));
                mx = mx+mx+mx - t1-t2-t3;
                if(m>=mx&&t1>=0&&t2>=0&&t3>=0) flag = true;
            }

            if(flag) printf("yes\n");
            else printf("no\n");
        }
    }



    return 0;
}
