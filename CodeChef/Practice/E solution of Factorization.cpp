#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
bool isPrime[N];
vector<int> primes;

void sieve()
{
    fill(isPrime, isPrime + N, true);
    for(int i = 2; i * i < N; i++) if(isPrime[i])
        {
            for(int j = i * i; j < N; j += i) isPrime[j] = false;
        }
    for(int i = 2; i < N; i++) if(isPrime[i]) primes.push_back(i);
}

int main()
{
    int T;
    cin >> T;
    sieve();
    while(T--)
    {
        long long n, phin;
        vector<long long> factors;
        long long sp, pp, dp;
        long double t;
        cin >> n >> phin;
        for(int p : primes) if(n % p == 0)
            {
                int powp = 0;
                while(n % p == 0) factors.push_back(p), n /= p, powp++;
                phin /= (p - 1);
                while(powp - 1) phin /= p, powp--;
                if(n == 1) break;
            }
        if(n == 1) goto printans;
        if(n == phin + 1)       // n = p
        {
            factors.push_back(n);
            goto printans;
        }
        // n = p1^2
        dp = sqrt(n);
        if((dp - 1) * (dp - 1) == n) dp--;
        if((dp + 1) * (dp + 1) == n) dp++;
        if(dp * dp == n)
        {
            factors.push_back(dp);
            factors.push_back(dp);
            goto printans;
        }
        // n = p1 * p2
        sp = n - phin + 1;  // p1 + p2
        pp = n;     // dp = |p1 - p2|
        t = (long double) sp * sp - (long double) 4.0 * pp;
        dp = sqrt(t);
        if((dp - 1) * (dp - 1) == t) dp--;
        if((dp + 1) * (dp + 1) == t) dp++;
        factors.push_back((dp + sp) / 2LL);
        factors.push_back((sp - dp) / 2LL);

printans:
        sort(factors.begin(), factors.end());
        for(long long f : factors) cout << f << " ";
        cout << "\n";
    }
    return 0;
}
