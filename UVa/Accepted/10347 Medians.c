#include <stdio.h>
#include <math.h>

int main()
{
    double u, v, w, s, area, root;

    while(scanf("%lf %lf %lf", &u, &v, &w) == 3)
    {
        s = (u + v + w)/ 2;
        root = s * (s - u) * (s - v) * (s - w);
        if (root > 0) area = 4 * sqrt(root)/ 3;
        else area = -1;
        printf("%.3lf\n", area);
    }
    return 0;
}
