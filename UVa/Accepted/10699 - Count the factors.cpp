#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 1000009
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
using namespace std;

int prime[sz], cnt, siv[sz];

void sieve()
{
    int sq = sqrt(sz);

    for (int i = 3; i<=sq; i+=2)
    {
        if(!siv[i])
        {
            for (int j = i*i; j<sz; j+=i+i)
            {
                siv[j]=true;
            }
        }
    }

    prime[cnt++]=2;

    for (int i = 3; i<sz; i+=2)
    {
        if(!siv[i])
        {
            prime[cnt++]=i;
        }
    }



    return;
}


int main()
{
    sieve();
    int n, m,s;
    while(~scanf("%d", &n)&&n)
    {
        m = 0;
        for (int i = 0;prime[i]<=n; i++)
        {
            if(n%prime[i]==0) m++;
        }
        printf("%d : %d\n", n, m);
    }

    return 0;
}
