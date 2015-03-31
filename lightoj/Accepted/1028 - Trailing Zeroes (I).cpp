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

using namespace std;

bool siv[sz];
long long prime[sz];
int c;

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
    c=0;
    prime[c++]=2;

    for (int i = 3; i<sz; i+=2)
        if(!siv[i]) prime[c++]=i;
    return;
}

int main()
{
    seive();
    long long t, cas=1;
    long long n, ans, sq,cnt,k;
    scanf("%lld", &t);
    while(t--)
    {
        ans=1;
        cnt=1;
        scanf("%lld", &n);

        for (int i = 0; i<c&&prime[i]*prime[i]<=n; i++)
        {
            if(n%prime[i]==0)
            {
                cnt=1;
                k=prime[i];
                while(n%k==0)
                {
                    n/=k;
                    cnt++;
                }
                ans*=cnt;
            }
        }
        if(n>1) ans<<=1;
        printf("Case %lld: %lld\n",cas++,ans-1);
    }
    return 0;
}
