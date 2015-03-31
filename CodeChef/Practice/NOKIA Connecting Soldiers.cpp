/**
* H:\Dropbox\Code\CodeChef\Practice\NOKIA Connecting Soldiers.cpp
* Created on: 2015-03-18-23.17.22, Wednesday
* Verdict: Solved
* Author: Enamul Hassan
* Concept: This problem has a dp solution, but I did it with greedy
           observation. Now, lets discuss the main theme. With some
           paper work for small cases, I observed that, all the
           permutations' outputs remains in a continuous range.
           That means, if we could find the highest and lowest value
           of this range, then its easy to calculate the rest. By
           observing a little bit deeply, we can see that it is
           related to partitioning. That means, we can divide the
           problem into same sub-problems with smaller range. If
           we take n spots, and choose the spot from either end,
           then the rest of the problem is for n-1 spots. Similarly,
           we can choose either end and call for n-2 and so on.
           This partitioning is very slow, because we are making
           the problem only one less than the problem was in the
           last step. This permutation could be 1 2 3 ... n
           So, by doing this, we are getting the highest value of
           the range.

           On the other hand, if we want to get the lowest value of
           the range, we have to divide the sub-problem into
           smallest possible part. In one step having n spots,we
           can divide it into two sub-problems of ceil(n/2) spots.
           Example: for n = 3, 2 1 3 or 3 1 2 is a possible
           permutation for getting the lowest value.

           The highest value can be found by a formula, but I did
           it generating the permutation and calculating from it.
           The formula is (n+1)*(n+2)/2-1.

           I calculated the lowest value by dividing into sub
           problems approach where base case is: if n = 2, then
           one of it is tower and another is spot. So, two miles
           wire needed. if n = 1, then it is a tower, so no need
           to use wire.

           If the purchased wire is smaller then the lowest value,
           then  -1 would be printed. If it is larger than largest
           value, then the difference between the largest value and
           the purchased wire would be the output, otherwise output
           would be zero!
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb(a) push_back(a)
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
using namespace std;

ll t, n, ans, m, high, low;
vector<int>v;
ll calc()
{
    ll now = 0, up, down;
    for(int co = 1; co<=n; co++)
        for (int i = 0; i<n; i++)
        {
            if(v[i]==co)
            {
                for (up = i+1; up<n; up++)
                    if(v[up]<co) break;
                now+=up-i;
                for (down = i-1; down>=0; down--)
                    if(v[down]<co) break;
                now+=i-down;
            }
        }
    return now;
}

ll calcs(int k)
{
    if(k<=1) return 0;
    if(k==2) return 2;
    int mid = k/2;
    return calcs(mid)+calcs(k-mid)+k;
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

    cin>>t;

    while(t--)
    {
        cin>>n>>m;

        low = calcs(n+1);
        v.clear();

        for (int i = 1; i<=n; i++)
            v.pb(i);
        high = calc();
        if(m<low) cout<<-1<<"\n";
        else if(m>=low && m<=high) cout<<0<<"\n";
        else cout<<m-high<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
