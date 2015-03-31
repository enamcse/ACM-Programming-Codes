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
#include <stack>

#define sz 55
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
using namespace std;

int main()
{
    ll m;
    int t, n, cas=1;
    double a, d, x, y,  lap, passed=0.0, p=1.0;

    scanf("%lf %lf %d", &a, &d, &n);
    while(n--)
    {
        lap= p * (d/a);
        m = (ll) lap;
        passed = (lap - (double)m);

        if(m%4==0)
        {
            x = passed * a;
            y = 0.0;
        }
        else if(m%4==1)
        {
            x = a;
            y = passed * a;
        }
        else if(m%4==2)
        {
            x = (1.0 - passed) * a;
            y = a;
        }
        else
        {
            x = 0.0;
            y = (1.0 - passed) * a;
        }

        printf("%lf %lf\n",x,y);
        p++;
    }


    return 0;
}
