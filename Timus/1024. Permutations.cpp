/**
* H:\Dropbox\Code\Timus\1024. Permutations.cpp
* Created on: 2015-03-16-01.56.52, Monday
* Verdict: Solved
* Author: Enamul Hassan
* Concept: At first we have to know some prerequisites like how it is forming
           a chain or cycle. Lets take the given example in the problem set.
                |1 2 3 4 5|
                |4 1 5 2 3|
           we have: P(1) = 4;P(P(1)) = P(4) = 2 and P(P(P(1))) =P(2) = 1.
           So, in this cycle the elements are 1 4 2. This cycle has no relation
           with any other existing cycle in the permutation. Say, P(3) = 5.
           P(P(3)) = P(5) = 3. Here, another cycle is found which has no relation
           with the previous cycle. The elements of this cycle are 3 5.

           In this problem, we have to understand what is EN(n). EN(n) is a
           function which takes a permutation and gives the same permutation
           again. If k could be 0, then the answer would always be zero as I
           am getting the same permutation without any iteration. Here, iteration
           means every element would walk one step through it cyclic path.
           If we apply one step on our example, what it would be? It would be:
                |1 2 3 4 5|
                |2 4 3 1 5|
           Here, we have: P(1) = 2;P(P(1)) = P(2) = 4 and P(P(P(1))) =P(4) = 1.
           So now, cycle elements became 2 4 1 from 1 4 2. Similarly for another
           cycle it became 5 3 from 3 5.

           However, in the problem, k should be a positive integer, that means it
           could not be 0. we have to find the k. k would be an integer which
           indicates after how many iteration, all the cycles would meet at their
           own initial states. A cycle having n elements meets its initial state
           after every n iterations. So, all the cycles would meet at an iteration
           number where all of them are at their initial states.
           Definitely, it is nothing but the LCM of the all cycle lengths.
           The cycle would never overlap, so we could do it having complexity O(n).
* Special Thanks to: Rumman Mahmud Mahdi Al Masud.
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define sz 2005
#define pb(a) push_back(a)
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;

int arr[sz];
bool col[sz];
int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, n, m, cas=1,res;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>n;

    for (int i = 1; i<=n; i++)
        cin>>arr[i];
    vector<int>ans;
    for (int i = 1; i<=n; i++)
    {
        if(col[i]) continue;
        t = 0;
        m = i;
        do
        {
            col[i] = true;
            m = arr[m];
            t++;
        }while(m!=i);
        ans.pb(t);
    }
    res = 1;
    for (int i = 0; i<ans.size(); i++)
        res = (res/__gcd(res, ans[i])*ans[i]);

    cout<<res;


//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
