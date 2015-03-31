/**
* H:\Dropbox\Code\Codeforces\340C.cpp
* Created on: 2015-03-14-01.10.35, Saturday
* Verdict: Solved
* Author: Enamul Hassan
* Concept: We would work on sorted data so that the problem becomes easy.
           So, we have to sort it first. However, Lets think about denominator
           first. Clearly, there exists n! ways to permute n elements.

           Now, think about numerator. We can divide it into two sub part.
           One calculates all distances from 0 and the one calculates the rest
           differences.

           Taking n elements, if we fixed the first element, then in how many
           ways we can permute the rest elements? Surely, (n-1)!
           So, every element would occur at first position in (n-1)! permutations.
           That means, the result of the first part would be:
            Sum1 = ((n-1)! * a1+(n-1)! * a2+...+(n-1)! * an), as |ai - 0| = ai
            Sum1 = (n-1)! * (a1+a2+...+an)
            Sum1 = (n-1)! * (sum of all elements)

           Lets think about the second part of the numerator. We have to calculate
           the sum of all |ai-aj| in all permutations where i and j ranges 1 to n
           and ai and aj are adjacent in the permutation.
           Now, lets fixed the position of aj at k. So, the position of aj is fixed
           at k+1. rest of the n-2 elements can be permuted in (n-2)! ways.
           At how many positions we can fixed aj? in other word, what are the
           possible values of k? definitely 1 to n - 1. That means,
            Sum2 = |ai-aj| * (n-1) * (n-2)!
            Sum2 = |ai-aj| * (n-1)!

           If we sum these two and write with denominator, then it would be:
            Answer = (Sum1+Sum2)/n!
            Answer = ((n-1)! * (sum of all elements) + |ai-aj| * (n-1)!)/n!
            Answer = (n-1)! * ((sum of all elements) + |ai-aj|)/(n * (n-1)!)
            Answer = ((sum of all elements) + |ai-aj|)/n

           The only remaining part is to calculate the sum of differences of all
           possible pairs which is not an easy task for 10^5 elements. A brute
           force approach would take 10^10 operations which would cause Time Limit.

           We can do it by counting how many times a value is added and how many
           time it is deducted. In term |ai - aj|, ai is added and aj is deducted.
           For the i-th value, it would be added in i-1 term and deducted in n-i.
           Say, a sequence a1 a2 a3 ... a(i-1) ai a(i+1)... an
           Paring with the values smaller than ai, it would remain as added value
           as |ai - ak| where k ranges 1 to i-1. Similarly, for the values greater
           than ai, it would remain as deducted value as |ak - ai| where k ranges
           i+1 to n.
           We have to multiply this result by two, because, a pair would occur twice.
           One time |ai - aj| and other time |aj - ai|.
           At last we have to divide both numerator and denominator by their GCD.
* Special Thanks to: --Denis Distrugatorul De Pizde
                       (http://codeforces.com/profile/Kira69)
                     --Rumman Mahmud Mahdi Al Masud
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define all(a) a.begin(),a.end()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
using namespace std;

ll sum,n;

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

    cin>>n;

    vector<ll>v(n);

    for (int i = 0; i<n; i++)
        cin>>v[i];

    sort(all(v));

    for (int i = 0; i<n; i++)
    {
        /**
        * Lets i-th element = a
        * for the first sub part, a should be added in sum.
        * for the second sub part add portion, 2*a*i should be added.
        * for the second sub part deduct portion, 2*a*(n-i-1) should be deducted.
        * So, total added in sum = a + 2ai- 2a(n-i-1)
        *                        = a + 2ai- 2an + 2ai + 2a
        *                        = a(1 + 2i - 2n + 2i + 2)
        *                        = a(4i - 2n + 3)
        */
        sum+=((i<<2)-(n<<1)+3LL)*v[i];
    }
    ll gcd = __gcd(sum,n);
    sum/=gcd;
    n/=gcd;

    cout<<sum<<" "<<n;

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
