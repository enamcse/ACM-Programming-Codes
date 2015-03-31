/**
* H:\Dropbox\Code\UVaLive\5807 - Maximum in the Cycle of 1.cpp
* Created on: 2015-03-15-11.29.31, Sunday
* Verdict: Solved
* Author: Enamul Hassan
* Concept: At first we have to know some prerequisites like how it is forming
           a chain or cycle. Lets take the given example in the problem set.
                |1 2 3 4 5 6 7 8|
                |3 2 5 4 1 7 8 6|
           we have: P(1) = 3;P(P(1)) = P(3) = 5 and P(P(P(1))) =P(5) = 1.
           So, in this cycle the elements are 1 3 5. This cycle has no relation
           with any other existing cycle in the permutation. Say, P(6) = 7;
           P(P(6)) = P(7) = 8 and P(P(P(6))) =P(8) = 6. Here, another cycle is
           found which has no relation with the previous cycle. The elements of
           this cycle are 6 7 8. 2 and 4 are in its original position. So, it
           would loop on itself infinitely! But the other two cycles' elements
           would be repeated once in every three iterations.
           Now, lets work with the problem and make it easier and simpler. The
           main problem is to find a cycle where 1 and k must exist and no
           element greater than k exists.
           This problem may solve using derangement mathematics, but I would
           try to solve using the other way.
           Now, k=1 is an exceptional case, lets think about k>1. We can make
           cycles of length 2, 3, 4, ... , k. we could not make length 1,
           because if we want to bring k in our cycle having 1 already, we have
           to take at least two elements.
           if we fix the cycle length, then all other elements can be rearranged
           among them independently. Say, we fixed the length L, so, rest n - L
           elements can be rearranged among them independently and it is (n-L)!
           Another thing would be calculated simultaneously, that is in length L,
           we can fill the first position with any elements except 1. That means,
           there are (L-1) possibilities. For the second position, we have (L-2)
           options. In this way the options would go like (L-3),(L-4),...,3,2,1
           which clearly making (L-1)!
           But there could arise a confusion. How could we calculate the
           possibilities of second position? From where L-2 came, right?
           Well, take an example of 3 elements: 1 2 3. If we fix 2 at the first
           position, then there are 2 options: 2 1 3 and 2 3 1, where the first
           one is invalid, because 3 is in its own position. If we fix 3 at the
           first position, then there are 2 options: 3 1 2 and 3 2 1, where the
           second one is invalid, because 2 is in its own position.
           So, there are three options for the first position, two and one for
           the second and third position respectively. You can observe more longer
           cycles if you are not clear at this point.
           Now, how many L length cycle is possible? we have to fix two position,
           one is position 1 and another one is position k. we can take other
           elements in (k-2)C(L-2) ways.
           So, for each L where 2<=L<=k, we have to multiply these three things
           and add it with our solution. That is:
                Answer+= (n-L)! * (L-1)! * (k-2)C(L-2);

           The one and only case is k = 1. If we fix 1 at its own position, then
           in how many ways the rest of the elements can permute independently
           among them? Yes, it is (n-1)!

* Special Thanks to: Rumman Mahmud Mahdi Al Masud.
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
using namespace std;

unsigned ll ncr[25][25], factorials[25];

bool t_ncr[25][25], t_factorials[25];

unsigned ll nCr(unsigned ll int n,unsigned ll int r)
{
    if(r==1) return n;
    if(n==r||r==0) return 1;
    unsigned ll &ret = ncr[n][r];
    if(t_ncr[n][r]) return ret;
    t_ncr[n][r] = true;
    ret = nCr(n-1,r)+nCr(n-1,r-1);
    return ret;
}
unsigned ll fact(unsigned ll n)
{
    if(n==0) return 1LL;
    unsigned ll &ret = factorials[n];
    if(t_factorials[n]) return ret;
    t_factorials[n]=true;
    ret=fact(n-1)*n;
    return ret;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>t;
    unsigned ll ans;
    while(t--)
    {
        cin>>cas>>n>>m;
        ans=0;
        for (int i = 2; i<=m; i++)
        {
            ans+=(fact(n-i)*nCr(m-2,i-2)*fact(i-1));
        }
        if(m==1) ans = fact(n-1);
        cout<<cas<<" "<<ans<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
