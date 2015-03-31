#include <cstdio>
#include <algorithm>

int main()
{
    int t, n, m, cas=1;
    double v[3], d, s,a[2];

    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf %lf", &v[0], &v[1], &v[2], &a[0], &a[1]);

        d = (v[0]*v[0]*0.5)/a[0];
        d+= (v[1]*v[1]*0.5)/a[1];
        if(v[0]/a[0]>v[1]/a[1]) s = std::max(v[1]/a[1],v[0]/a[0])*v[2];
        else s = (v[1]/a[1])*v[2];

        printf("Case %d: %lf %lf\n", cas++, d, s);
    }

    return 0;
}
