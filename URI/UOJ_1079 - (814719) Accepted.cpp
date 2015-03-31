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
    int a;
    double x, y, z, avg;
    scanf("%d", &a);

    while(a--)
    {
        scanf("%lf %lf %lf", &x, &y, &z);
        avg = (x*2.0+y*3.0+z*5.0)/10.0;
        printf("%.1lf\n", avg);
    }



    return 0;
}
