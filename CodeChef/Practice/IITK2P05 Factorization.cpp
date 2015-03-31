/**
* H:\Dropbox\Code\CodeChef\Practice\IITK2P05 Factorization.cpp
* Created on: 2015-03-06-01.40.58, Friday
* Verdict: Solved
* Author: Enamul Hassan
* Problem Link: http://www.codechef.com/problems/IITK2P05
* Concept: This is a very interesting number theory problem. Lets think the problem if
           n ranges to 10^12. What would we do? we would generate all the primes up to
           10^6 and would apply them on n. at last if n>1 then that value would be added
           in answer. Before going to the original constraint, we have to know some basic
           number theory formulas. They are:
           phi( n * m) = phi(n) * phi(m)
           phi( n ) =  n * ( 1 - (1/p1) )* ( 1 - (1/p2) ) * ... * ( 1 - (1/pk) )
           phi( n ) =  ( p1^(e1-1) )* (  p2^(e2-1) ) * ... * ( pk^(ek-1) ) *( p1 - 1)
                                                                    *(p2-1)* ... *(pk-1)
          where pi is i-th prime factor of n and ei is the corresponding power of that
          prime factor.
          Another thing is to know that, phi(x) = x - 1 satisfies only when x is prime.
          Now, lets face the main problem. At first, we have to find all prime factors of
          n less than 10^6. The corresponding phi calculation should be deducted from m.
          How the corresponding phi would be deducted from m? 3rd formula would help.
          For a prime factor pi, we know its corresponding power in n which is ei. So, the
          new m would be m/(( pi^(ei-1) ) * (pi - 1 )).
          Now, only primes greater than 10^6 are remaining in n. This part of the calculation
          would be needed if n remains greater than one after the above calculation. It is
          guaranteed that there could exists at most two primes. Because, if any number below
          or equal to 10^18 have more than two prime factor, one of them must remain in range
          10^6. Because, 10^6 *10^6 * 10^6  = 10^18.
          There are 3 possibilities which would be described below:
          1. n could be a prime if n = m + 1. So, n itself a prime, no calculation needed.
          2. n could be square number of a prime. In this case phi would be (p-1) * (p-1).
             Because, prime number p has phi, m = p - 1 and phi(p * p) = (p-1) * (p - 1).
          3. n could be the resultant of two different primes multiplication. suppose, these
          two primes are a and b. So,
                                a * b = n ............................(1) and
                                m = (a - 1) * (b - 1)
                                m = a*b - a - b + 1
                                m = n - (a + b) + 1
                                a + b = n - m + 1 ....................(2)
         We know, (a - b)^2 = (a + b)^2 - 4 * a * b
                  a - b = square_root( (n - m + 1)^2 - 4 * n ) .......(3)
         (2) - (3) =>
                    b = ( (n - m + 1) - square_root( (n - m + 1)^2 - 4 * n ) )/2
         From (1),
                    a = n/b

* Special thanks to: Sudipta Chandra Dipu and Kazi Nayeem
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;

ll n, m,t;
vector<ll>ans;

#define sz 1000010
ll col[sz/64+10];
int prime[78499+10], cnt;

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

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    seive();
//    cout<<cnt<<endl;
    cin>>t;

    while(t--)
    {
        cin>>n>>m;
        ans.clear();
        for (int i = 0;i<cnt&& prime[i]*prime[i]<=n; i++)
        {
            if(n%prime[i]==0)
            {
                ll cn=1;
                n/=prime[i];
                ans.pb(prime[i]);
                while(n%prime[i]==0)
                {
                    n/=prime[i];
                    cn*=prime[i];
                    ans.pb(prime[i]);
                }
                m = m/(cn*(prime[i]-1));
            }
        }
        if(n>1)
        {
            if(n==m+1) ans.pb(n);
            else if((n-m)*(n-m)==n)
            {
                ans.pb(n-m);
                ans.pb(n-m);
            }
            else
            {
                long double x = n-m+1;
                m= x-sqrtl((x*x)-(n<<2LL));
                m>>=1;
                ans.pb(m);
                ans.pb(n/m);
            }
        }
//        sort(all(ans));
        m = ans.size();
        for (int i = 0; i<m; i++)
            cout<<ans[i]<<" \n"[i==m-1];
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
