#include <bits/stdc++.h>

#define sz 13055
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

int fact[10005], factors[10005];

bool siv[10205];
int primes[10005], cnt;


void seive()
{
    int len = 105;
    for (int i = 3; i<=len; i+=2)
        if(!siv[i])
            for (int j = i*i; j<10201; j+=i+i)
                siv[j] = true;
    primes[cnt++]=2;
    for (int i = 3; i<10201; i+=2)
        if(!siv[i]) primes[cnt++] = i;
    return;
}

void factorize(int n)
{
    for (int i = 0; primes[i]<=n; i++)
    {
        if(n%primes[i]==0)
        {
            int cnt = 0;
            while(n%primes[i]==0) n/=primes[i],cnt++;
            factors[i]+=cnt;
        }
    }
}

int toPower(int n, int p)
{
    int a = n%10;
    for (int i = 1; i<p; i++)
        a*=n,a%=10;
    return a;
}


void calc(int n)
{
    int now = 1;
    if(factors[0]>factors[2])
    {
        now*=toPower(primes[0], factors[0]-factors[2]);
        now%=10;
    }
    else if (factors[0]<factors[2])
    {
        now*=toPower(primes[2], factors[2]-factors[0]);
        now%=10;
    }
    if(factors[1])now*=toPower(primes[1], factors[1]);
    now%=10;
    for (int i = 3; primes[i]<=n; i++)
    {
        if(factors[i])now*=toPower(primes[i], factors[i]);
        now%=10;
    }
    fact[n] = now;
    return;
}

int main()
{
#ifdef ENAM
    fread;
    fwrite;
#endif // ENAM
    seive();
    int t, n, m, cas=1;
    fact[0]=1;
    fact[1]=1;

    for (int i = 2; i<=10000; i++)
    {
        factorize(i);
        calc(i);
    }

    while(scanf("%d", &n)==1)
        printf("%5d -> %d\n", n, fact[n]);
    return 0;
}
