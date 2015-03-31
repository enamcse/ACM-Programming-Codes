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

#define sz 1000100
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

ll a, b, c, L;
bool siv[sz];
int prime[sz],cn;

void seive()
{
    int sq = sqrt(sz);
    for (int i = 3; i<=sq; i+=2)
    {
        if(!siv[i])
        {
            for (int j = i*i; j<sz; j+=i+i)
                siv[j]=true;
        }
    }
    prime[cn++]=2;
    for (int i = 3; i<sz; i+=2)
        if(!siv[i]) prime[cn++]=i;
    return;
}

void solve()
{
    int p;
    for (int i = 0; i<cn; i++)
    {
        if(prime[i]>a && prime[i]>b) break;
        p=0;
        while(a%prime[i]==0)
        {
            a/=prime[i];
            if(b%prime[i]==0) b/=prime[i];
            L/=prime[i];
            p++;

        }
        while(b%prime[i]==0)
        {
            b/=prime[i];
            L/=prime[i];
            p++;
        }
        if(L%prime[i]==0)
        {
            while(p--) L*=prime[i];
        }
    }
    c=L;
    return;
}



int main()
{
    int t, n, m, cas=1;
    seive();

    scanf("%d", &t);

    while(t--)
    {
        scanf("%lld %lld %lld", &a,&b,&L);

        if(L%a!=0 || L%b!=0)
        {
            printf("Case %d: impossible\n",cas++);
            continue;
        }

        solve();

        printf("Case %d: %lld\n",cas++,c);
    }



    return 0;
}
