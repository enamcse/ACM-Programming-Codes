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
    double a,b;
    int r;
    scanf("%d", &r);
    r*=(r*r);
    r<<=2;
    printf("VOLUME = %.3lf\n", PI*r/3.0);
    return 0;
}