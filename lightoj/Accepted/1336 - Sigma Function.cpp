/**
* H:\Dropbox\Code\1336 - Sigma Function.cpp
* Created on: 2015-03-03-04.25.25, Tuesday
* Verdict: Solved
* Author: Enamul Hassan
* Concept:  Lets consider the naive approach to attack the problem. Here, we will have
            to find, how many integers from 1 to n have even value of sigma, where
            sigma(m) is the summation of the divisors of m. It can also be expressed
            by the following:
            sigma(m) = ((p1^(e1+1)-1)/(p1-1))*((p2^(e2+1)-1)/(p2-1))*...
                                                               *((pk^(ek+1)-1)/(pk-1))
            where, p1, p2, ...,pk are the prime factors of m and and e1,e2,...,ek are
            the corresponding powers of primes.
            Now, let think about one term instead of k. It can be written:
            (p1^(e1+1)-1)/(p1-1) = (p1-1)(p1^e1+p1^(e1-1)+p1^(e1-2)+...+p1^0)/(p1-1)
                                 = (p1^e1+p1^(e1-1)+p1^(e1-2)+...+1)
            In sigma(m), if any of the terms become even then sigma(m) would be even.
            At first we would think about primes other than 2. We would think about
            this very first prime later.
            From the expansion of a term, we found that
            (pi^ei+pi^(ei-1)+pi^(ei-2)+...+1) would be even, if ei would be odd.
            Similarly, (pi^ei+pi^(ei-1)+pi^(ei-2)+...+1) would be odd, if ei would be
            even.
            Lets think reversely. sigma(m) would be odd if and only if all of the
            terms in sigma(m) would be odd. If we could find out the number of number
            which have odd sigma value, then we would be able to find out the answer
            by subtracting it from n.
            Now, lets think a number K which may have prime factor having odd power.
            Now, K^2 have the same prime factors as K, but with even powers only.
            The very first prime 2 was out of consideration till now. Now, think
            about the prime 2. The term with this number would always be odd, however
            the power. e.g. 2^0-1=0, 2^1-1=1, 2^2-1=3 etc. So, we have to find out the
            numbers 2^i * K^2, where i ranges 1 to 40 and K is an odd number.
            This solution would work but would have chance to get MLE if not
            implemented optimally.
            However, This problem has a O(1) solution.
            lets n1 is a number which has even power of number 2 in its factorization.
            So, n1 = 2^(2i)*P^2
            n1 = (2^i * P)^2
            2^i * P = n1^0.5 where i ranges from 0 to x.
            lets n2 is a number which has odd power of number 2 in its factorization.
            So, n2 = 2^(2i+1)*P^2
            n2/2 = 2^(2i)*P^2
            n2/2 = (2^i * P)^2
            2^i * P = (n1/2)^0.5 where i ranges from 0 to x.
            So, the answer is n - n1 - n2 = n - (2^i * P)^2 - (2^i * P)^2.
* Special Thanks to: Khan Muhammad Rumman Mahmud Mahdi Al Masud.
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
using namespace std;
/**
#define sz 1000010
ll arr[1707106+10], n_cnt;
*/
int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t,cas=1;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    ll n=sz, ans, last = 1e12;
    /// The commented codes with two stars is the implementation of the first approach.
    /**
    for (int i = 0; i<=40; i++)
    {
        ll now = (1LL<<i), then;
        for (int j = 1; j<n; j+=2)
        {
            then = j;
            then*= j;
            if(now<=last/then)
            arr[n_cnt++]=now*then;
            else break;
        }

    }
    sort(arr,arr+n_cnt);
    */
    cin>>t;
    while(t--)
    {
        cin>>n;
        /**
        ans = upper_bound(arr,arr+n_cnt,n)-arr;
        */
        ans = sqrt(n*1.0);
        ans+= sqrt(n/2.0);
        cout<<"Case "<<cas++<<": "<<n-ans<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
