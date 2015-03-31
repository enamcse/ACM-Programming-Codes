/**
* H:\Dropbox\Code\CodeChef\Practice\IITK2P01 Little Chef and the King.cpp
* Created on: 2015-03-05-01.02.32, Thursday
* Verdict: Solved
* Author: Enamul Hassan
* Problem Link: http://www.codechef.com/problems/IITK2P01
* Concept: A simple greedy approach would work in this problem. We would start from the largest
           power of K which satisfies K^i <= n where i is the largest power of K which satisfies
           the equation. Then we would continue subtracting until n < K^i and would repeat the
           process decreasing i by one. Just subtracting may not work in time limit. So, we would
           divide n by K^i and then subtract the result from n after multiplying it K^i. This
           process would continue till i = 0.
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;


ll arr[100], cnt;
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

    ll t, n, k, now, ans;

    cin>>t;
    while(t--)
    {
        ans = 0;
        cnt = 0;
        now=1;
        cin>>n>>k;

        if(k==1)
        {
            cout<<n<<"\n";
            continue;
        }

        while(now<=n)
        {
            arr[cnt++] = now;
            now*=k;
        }

        while(cnt--&&n)
        {
            now = n/arr[cnt];
            ans+=now;
            n-=(arr[cnt]*now);
        }

        cout<<ans<<endl;

    }
//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
