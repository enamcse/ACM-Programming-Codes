/**
* H:\Dropbox\Code\lightoj\1137 - Expanding Rods.cpp
* Created on: 2015-02-05-04.04.13, Thursday
* Verdict: Solved
* Author: Enamul Hassan
**/

#include <stdio.h>
#include <math.h>

using namespace std;

double LP, L;

bool check(double r)
{
    return LP - (2.0* r * asin(0.5*L/r))>=0;
}

int main()
{
#ifdef ENAM
//    	fread;
//	fwrite;
#endif // ENAM
    int t,  cas=1;
    double n, C, lef, rig, mid;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%lf %lf %lf", &L, &n, &C);
        LP = (1+n*C)*L;
        lef = 0;
        rig = 1e8;
        for (int i = 0; i<60; i++)
        {
            mid = (lef+rig)/2.0;

            if(check(mid)) rig = mid;
            else lef = mid;
        }
        mid-=sqrt(mid*mid - (L*L/4.0));
        if((LP-L)<1e-12) mid = 0;
        printf("Case %d: %.9lf\n", cas++, mid);
    }

   return 0;
}
