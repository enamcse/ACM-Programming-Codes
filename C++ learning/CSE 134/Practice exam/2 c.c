#include <stdio.h>

int main()
{
    char str[] = "ALL56PLUS72IS128";
    int a, i;
    for (i = 0; i < 14; ++i)
    {
        if(str[i] < 'A') a = str[i] - '0';
        else a = str[i] - 'A';
        printf("%d value-> %d\n", i, a*a);
    }
    return 0;
}
