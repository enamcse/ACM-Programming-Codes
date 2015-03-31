#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define sz 100
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1<<30-1)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI 3.14159
using namespace std;

int main()
{
    _
    double a,b,c, aa, bb, cc, dd, ee;
    scanf("%lf %lf %lf", &a, &b, &c);
    aa = a*c/2;
    bb = PI*c*c;
    cc = (a+b)*c/2;
    dd = b*b;
    ee = a*b;
    printf("TRIANGULO: %.3lf\nCIRCULO: %.3lf\nTRAPEZIO: %.3lf\nQUADRADO: %.3lf\nRETANGULO: %.3lf\n", aa,bb,cc,dd,ee);
    return 0;
}
