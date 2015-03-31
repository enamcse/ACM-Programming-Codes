/**
* H:\Dropbox\Code\lightoj\1163 - Bank Robbery.cpp
* Created on: 2015-02-26-20.16.07, Thursday
* Verdict: Not Solved
* Author: Enamul Hassan
* Comment: This problem gives Runtime Error Verdict if used cin, cout with sync.
* Concept: Let, the given number is X = A - B. Here, B = A/10.
            So, A - A/10 = X
                A - (A-A%10)/10 = X
                10A - A + (A%10) = 10X
                9A = 10X - K , let K = A%10
                A = (10X - K)/9
                A = X + (X - K)/9
            For K equals to 0 to 9, if (X - K)%9 = 0, then A would be a solution.
            If we get a solution for K = 0, then we would also get a solution for
            K = 9 in this case. That means, if X%9 = 0, then there exists two
            solutions: A = X + X//9 - 1 and A = X + X//9.
            Otherwise the only solution would be A = X + X//9, where '//'
            indicates integer division.
**/

#include <stdio.h>
#define ll long long

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t, cas=1;
    ll s, a, now;
//    _
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    scanf("%d", &t);

    while(t--)
    {
        scanf("%lld", &s);
        printf("Case %d: ",cas++);

        if(s%9==0) printf("%lld %lld\n", s + s/9 - 1, s+s/9);
        else printf("%lld\n", s+s/9);
    }



//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

   return 0;
}
