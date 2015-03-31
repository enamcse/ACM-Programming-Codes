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

double CF[12];
int n;

double find_val(double val)
{
    double res = CF[0];
    val+=1.0;
    for (int i = 1; i<=n; i++)
        res += (CF[i]/pow(val,i));
    return res;
}

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t,  m, cas=1;
    double left, right,val,ans, mid, ans2;
    while(~scanf("%d", &n)&&n)
    {
        for (int i = 0; i<=n; i++)
            scanf("%lf", &CF[i]);

        left = -1.0+1e-10;
        right = 1e10;
        ans2 = ans = - 2.0;
        for (int i = 0; i<80; i++)
        {
            mid = (right+left)/2.0;
            val = find_val(mid);
            if(abs(val)<1e-9)
            {
                ans = mid;
                break;
            }
            else if(val>0.0) left = mid;
            else right = mid;
        }
        if(ans==-2.0)
        {
            printf("No\n");
            continue;
        }

        left = ans;
        right = 1e10;
        ans2 = - 2.0;
        for (int i = 0; i<80; i++)
        {
            mid = (right+left)/2.0;
            val = find_val(mid);
            if(abs(val)<1e-9)
            {
                ans = mid;
                break;
            }
            else if(val>0.0) left = mid;
            else right = mid;
        }
        if(ans2!=-2.0)
        {
            printf("Too many\n");
            continue;
        }
        left = -1.0+1e-10;
        right = ans;
        ans2 = - 2.0;
        for (int i = 0; i<80; i++)
        {
            mid = (right+left)/2.0;
            val = find_val(mid);
            if(abs(val)<1e-9)
            {
                ans = mid;
                break;
            }
            else if(val>0.0) left = mid;
            else right = mid;
        }
        if(ans2!=-2.0)
        {
            printf("Too many\n");
            continue;
        }
        else printf("%.2lf\n", ans);
    }

    return 0;
}
