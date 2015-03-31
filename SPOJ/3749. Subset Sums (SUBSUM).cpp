#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include<set>

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

vector<ll>a,b,x,y;

int main()
{
    ll n, LL, UL, len_a, len_b, val, mask_len, sum;
    scanf("%lld", &n);
    len_a = (n>>1);
    len_b = n-len_a;
    scanf("%lld %lld", &LL, &UL);
    for (int i = 0; i<len_a; i++)
    {
        scanf("%lld", &val);
        a.pb(val);
    }
    for (int i = 0; i<len_b; i++)
    {
        scanf("%lld", &val);
        b.pb(val);
    }
//    if(n==1)
//    {
//        if(b[0]>LL&&&b[0]<UL)printf("%ll", 1);
//        else printf("%ll", 0);
//        return 0;
//    }
    mask_len = (1<<len_a);
    for (int i = 0; i<mask_len; i++)
    {
        sum = 0;
        for (int j = 0; j<len_a; j++)
        {
            if((i&(1<<j)))
            {
                sum+=a[j];
            }
        }
        x.pb(sum);
    }

    mask_len = (1<<len_b);
    for (int i = 0; i<mask_len; i++)
    {
        sum = 0;
        for (int j = 0; j<len_b; j++)
        {
            if((i&(1<<j)))
            {
                sum+=b[j];
            }
        }
        y.pb(sum);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    len_b = y.size();
    sum=0;
    for (int i = 0; i<len_b; i++)
    {
        val = y[i];
        sum+= (upper_bound(x.begin(),x.end(),UL-val)- lower_bound(x.begin(),x.end(),LL-val));
    }
    printf("%lld", sum);
    return 0;
}
