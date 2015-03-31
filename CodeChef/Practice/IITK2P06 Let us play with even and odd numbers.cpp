/**
* H:\Dropbox\Code\CodeChef\Practice\IITK2P06 Let us play with even and odd numbers.cpp
* Created on: 2015-03-05-01.54.33, Thursday
* Verdict: Solved
* Author: Enamul Hassan
* Problem Link: http://www.codechef.com/problems/IITK2P06
* Concept: If I give 2 to one side, then 3 should be given to the other side to satisfy
           the condition 2:3. More specifically, equation 2x + 3x = sum should satisfy
           where x is any positive number, 2x should be number of even numbers and 3x
           should be the number of odd numbers, sum = e + o.
           So, 5x = sum, x = sum/5.
           This equation says that sum of e and o should be divided by 5 without having
           any reminder, otherwise there could not exist any ratio like 2:3.
           Here, if we increase one side by one, then the other side would decrease by 1.
           So, if we fix one side, it would automatically fix the other side. We can find
           the x from the above equation. In the even side, we have to have 2x number.
           So, we have to make e to 2x. So, the absolute difference between e and 2x is
           the answer.
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)


using namespace std;

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

    ll t, o, e, sum;
    cin>>t;

    while(t--)
    {
        cin>>e>>o;

        if((e+o)%5!=0)
        {
            cout<<"-1\n";
            continue;
        }
        sum = (e+o)/5;
        sum*=2;
        cout<<abs(sum-e)<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
