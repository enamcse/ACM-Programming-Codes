/**
* H:\Dropbox\Code\lightoj\1289 - LCM from 1 to n.cpp
* Created on: 2015-02-26-14.44.24, Thursday
* Verdict: Solved
* Author: Enamul Hassan
* Concept:  We should figure out the primes below n and its highest power below
            or equal to n. It is enough to calculate the result by multiplying
            primes raising the highest powers.
                RESULT = P1^F1 * P2^F2 * ... +* Pm^Fm,
                where P1, P2, ... Pm are primes and F1, F2, ... Fm are the highest
                powers of them respectively.
            Mod operation would be handled by "unsigned int" type automatically.
            An observation is that, only those primes would have power greater
            than one which are below or equal to square root of n. So, its easy
            to calculate the multiplication of all primes below or equal to n.
            Then we would multiply this answer by the primes below or equal to
            square root of n raising to the power one less than the highest power.
            In short,
                RESULT = P1 * P2 * ... +* Pm,
                where P1, P2, ... Pm are primes below or equal to n.
                RESULT = RESULT * P1^(F1-1) * P2^(F2-1) * ... +* Pk^(Fk-1),
                where P1, P2, ... Pk are primes below or equal to square root of
                n and F1, F2, ... Fk are the highest powers of them respectively.
**/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define sz 100000100

const int real_size = 5761509;

ll col[sz/64+10];
int prime[real_size], cnt;
unsigned dp[real_size];
void seive()//1 indexed
{
    long long i,j,k;
    for(i=3;i<sz;i+=2)
         if(!(col[i/64]&(1LL<<(i%64))))
                for(j=i*i;j<sz;j+=2*i)
                    col[j/64]|=(1LL<<(j%64));

    prime[cnt++]=2;
    for (int i = 3; i<sz; i+=2)
        if(!(col[i/64]&(1LL<<(i%64))))
            prime[cnt++] = i;
}


unsigned find_sqrt_ans(int x)
{
    int k = sqrt(x), now;
    unsigned ret=1, cnts;
    for (int i = 0; prime[i]<=k; i++)
    {
        now = x/prime[i];
        cnts=1;
        while(now>=prime[i])
        {
            now/=prime[i];
            cnts*=prime[i];
        }
        ret*=cnts;
    }
    return ret;
}


int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1;
    unsigned ans;
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    seive();
    dp[0]=2;
    for (int i = 1; i<real_size; i++)
        dp[i]=dp[i-1]*prime[i];
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);
        ans=find_sqrt_ans(n);
        ans*=dp[upper_bound(prime,prime+cnt,n)-prime-1];
        printf("Case %d: %u\n", cas++,ans);
    }


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
