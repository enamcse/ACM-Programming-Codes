#include <stdio.h>

int main()
{
    char *c="Extraordinary---2010Session";
    int a = 5;
    double b =55.63;
    printf("%03d %1.4E %.13s %.7s %.4s:\n", a, b, c, (c+20), (c+16));
    printf("%d%% %.6lf \"%.5s\"\\\'%-18.13s\':", a, b, c, c);
    return 0;
}
