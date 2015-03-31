#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main()
{
    _
    int n;
    double a, b;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%lf %lf", &a, &b);
        if(b==0.0) printf("divisao impossivel\n");
        else
        {
            printf("%.1lf\n",a/b);
        }
    }

    return 0;
}
/*
3
3 -2
-8 0
0 8
*/
