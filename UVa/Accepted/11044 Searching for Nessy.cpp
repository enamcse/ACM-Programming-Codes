#include <stdio.h>
int main()
{
    int t, a, b, m, n, sonar;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &m, &n);
        a = m/3;
        b = n/3;
        sonar = a * b;
        printf("%d\n", sonar);
    }

    return 0;
}
