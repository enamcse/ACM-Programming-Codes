/**
* H:\Dropbox\Code\CodeChef\Practice\LUCKY8 Little Elephant and Product.cpp
* Created on: 2015-03-19-03.10.31, Thursday
* Verdict: Solved
* Author: Enamul Hassan
* Concept: This problem can be solved easily by using Digit DP. The parameter
           would be:
                1. Current digit number which is now processing,
                2. number of four I could take,
                3. number of five.
                4. start flag
                5. end flag
           where flags determine the current digit range.
           The combination of this five parameter would give the same result
           and they would be used repeatedly. So, we can use them as DP
           parameter. The base case would be: when the last digit processing
           is finished, then I can calculate the result by multiplying the
           number of four and the number of seven.

           The start flag on means I already put a digit which is greater than
           the corresponding digit in smaller number, here L, so now I can put
           any of 10 digits in this position, otherwise I could put only those
           digits which are greater than or equal to the corresponding digit
           in L.

           Similarly, the end flag on means I already put a digit which is
           less than the corresponding digit in larger number, here R, so now
           I can put any of 10 digits in this position, otherwise I could put
           only those digits which are less than or equal to the corresponding
           digit in R.

           If the current digit equal to 4 or 7 , the parameter number of four
           or seven would be increased by 1.

           Why we add one thing in dp parameter? because, without this parameter
           the overlapping calls would give the same value, but actually it
           should differ. In these problem, these five parameter could uniquely
           say that, if any call comes with the same parameter here, then it
           should walk the same way which I already walked and stored the result.
           So, no need to walk the same way my friend! take the result from me!

           One important thing is that, length of both number should be same.
           So, if it is not same, we would make it same.
**/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define clr(abc,z) memset(abc,z,sizeof(abc))
using namespace std;

string a,b;
int n,dp[20][20][20][2][2];

int rec(int pos, int four, int seven, bool low, bool high)
{
    if(pos == n) return four*seven;
    int &ret = dp[pos][four][seven][low][high];
    if(ret != -1) return ret;
    ret = 0;
    for (int i = (low?'0':a[pos]); i<= (high?'9':b[pos]); i++)
        ret = max(ret, rec(pos+1,four+(i=='4'),seven+(i=='7'),
                           low | (i > a[pos]), high | (i < b[pos])));
    return ret;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t;
    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cin>>t;

    while(t--)
    {
        cin>>a>>b;
        clr(dp,-1);
        n = b.size();
        while(n>a.size()) a='0'+a;

        cout<< rec(0,0,0,0,0) <<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
