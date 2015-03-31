#include <stdio.h>

int main()
{
    int hh,  mm;
    double h1, m1, degree;

    scanf("%d:%d", &hh, &mm);

    while(hh != 0 || mm != 0)
    {
        h1 = hh;
        m1 = mm;
        if (hh == 12) h1 = 0;
        degree = (30 * h1 + m1 / 2) - (6 * m1);
        if (degree < 0) degree = - degree;
        if (degree > 180) degree = 360 - degree;

        printf("%.3lf\n", degree);
        scanf("%d:%d", &hh, &mm);
    }
    return 0;
}
