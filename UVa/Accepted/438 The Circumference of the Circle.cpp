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
#define PI acos(-1)
using namespace std;

int main()
{
    _
    double x[3], y[3], c,r,s,a,b;
    while(~scanf("%lf %lf %lf %lf %lf %lf", &x[0], &y[0],&x[1], &y[1], &x[2], &y[2]))
    {
        a = sqrt(((x[0]-x[1])*(x[0]-x[1]))+((y[0]-y[1])*(y[0]-y[1])));
        b = sqrt(((x[2]-x[1])*(x[2]-x[1]))+((y[2]-y[1])*(y[2]-y[1])));
        c = sqrt(((x[0]-x[2])*(x[0]-x[2]))+((y[0]-y[2])*(y[0]-y[2])));
        s = (a+b+c)*0.5;
        r = ((a*b*c)/(4*sqrt(s*(s-a)*(s-b)*(s-c))));
        c = 2*PI*r;
        printf("%.2lf\n",c);
    }
    return 0;
}
