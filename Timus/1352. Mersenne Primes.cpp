/**
* H:\Dropbox\Code\Timus\1352. Mersenne Primes.cpp
* Created on: 2015-03-16-23.25.19, Monday
* Verdict: Solved
* Author: Enamul Hassan
* Concept: All the answers are given in the problem statement. Just seek
           and gather them. Only 3 to 8 number powers are not given.
           Any brute force algorithm would work. You can find them off-line
           and put them. The brute force algorithm are given in the comment.
           How to check n is prime or not? A very naive approach can be like:
           having a loop through 2 to n - 1 where any of the value can divide
           n without any remainder, that means mod value equals to zero. If
           any value can divide, then it is not prime, otherwise it is a prime.
**/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)

using namespace std;

map<int,int>ans;

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

    int t, n;

    ans[1]=2;
    ans[2]=3;
    ans[3]=5;
    ans[4]=7;
    ans[5]=13;
    ans[6]=17;
    ans[7]=19;
    ans[8]=31;
    ans[9]=61;
    ans[10]=89;
    ans[11]=107;
    ans[12]=127;
    ans[13]=521;
    ans[14]=607;
    ans[15]=1279;
    ans[16]=2203;
    ans[17]=2281;
    ans[18]=3217;
    ans[19]=4253;
    ans[20]=4423;
    ans[21]=9689;
    ans[22]=9941;
    ans[23]=11213;
    ans[24]=19937;
    ans[25]=21701;
    ans[26]=23209;
    ans[27]=44497;
    ans[28]=86243;
    ans[29]=110503;
    ans[30]=132049;
    ans[31]=216091;
    ans[32]=756839;
    ans[33]=859433;
    ans[34]=1257787;
    ans[35]=1398269;
    ans[36]=2976221;
    ans[37]=3021377;
    ans[38]=6972593;

//    for (int i = 3; i<=31; i++)
//    {
//        ll k = (1LL<<i)-1;
//        cout<<i<<": "<<k<<endl;
//        int j;
//        for (j = 2; j<k; j++)
//            if(k%j==0) break;
//        if(j==k) cout<<"prime"<<endl;
//    }
    cin>>t;

    while(t--)
    {
        cin>>n;
        cout<<ans[n]<<"\n";
    }

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
