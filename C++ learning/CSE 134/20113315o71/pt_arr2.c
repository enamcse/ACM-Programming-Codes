#include <stdio.h>

int main()
{
    double arr[] = {3.4, 2.5, 7.6,
                    1.9, 5.0, 2.5};
    double *pt = &arr[30];
    printf("%lf\n", *(pt++));
    printf("%lf\n", *(++pt));
    return 0;

}
