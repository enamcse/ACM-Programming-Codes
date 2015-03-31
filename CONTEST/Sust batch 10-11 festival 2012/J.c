#include <stdio.h>

int main()
{
    int num[3], n, min_max,caseno=1;

    scanf(" %d ", &n);
    while(n--)
    {
        scanf(" %d %d %d", &num[0], &num[1], &num[2]);
        min_max = num[0]>num[1]?(num[0]<num[2]?num[0]:(num[1]>num[2]?num[1]:num[2])):(num[1]<num[2]?num[1]:(num[0]>num[2]?num[0]:num[2]));
        printf("Case %d: %d\n",caseno++, min_max);
    }
    return 0;
}
