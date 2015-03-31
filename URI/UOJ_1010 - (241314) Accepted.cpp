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
    double a,b;
    int c,d;
    scanf("%*d %d %lf %*d %d %lf", &c, &a, &d, &b);
    printf("VALOR A PAGAR: R$ %.2lf\n", a*c+b*d);
    return 0;
}
