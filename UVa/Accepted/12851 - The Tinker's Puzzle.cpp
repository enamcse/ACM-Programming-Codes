/**
* H:\Dropbox\Code\UVa\12851 - The Tinker's Puzzle.cpp
*
* Created on: 2014-11-04-23.35.28, Tuesday
* Author: Enamul Hassan
* Verdict: SOLVED
**/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifdef ENAM
//    	fread;
//	fwrite;
    #endif // ENAM
    int t, n, m, cas=1;
    const double cons=615.52037419768436141931732028867;// (48*282/7*PI)
    int D, V;
    double ans;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &D, &V);
        ans = sqrt((cons*V)/D);
        printf("Case %d: %.3lf\n", cas++, ans);
    }

    return 0;
}
