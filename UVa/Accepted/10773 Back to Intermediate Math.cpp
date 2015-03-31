#include <stdio.h>
#include <math.h>

int main()
{
    int n, caseno=1;
    double t1, t2, u, v, w, u_sin, d, d_prime, del_t, theta;
    scanf("%d ", &n);
    while(n--)
    {
        scanf("%lf %lf %lf", &d, &v, &u);
        if(u>v&&u!=0&&v!=0)
        {
            u_sin = sqrt((u * u) - (v * v));
            t2 = d/u_sin;
            w = sqrt((u*u)+(v*v));
            theta = atan(v/u);
            d_prime = d/cos(theta);
            t1 = d_prime/w;
            del_t = t2 - t1;
            printf("Case %d: %.3lf\n", caseno++, del_t);
        }
        else printf("Case %d: can't determine\n", caseno++);
    }
    return 0;
}
