#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, k, n, len;
    char a[110], temp;

    scanf("%d", &n);

    while (n != 0)
    {
        k = 0;
        gets(a);

        len = strlen(a)/n;

        for (i = 0; i < len; ++i)
            for (j = 0; i < n/2; ++j, k++)
            {
                temp = a[k + j];
                a[k + j] = a[k + 5 - j];
                a[k + 5 - j] = temp;
            }

        puts(a);
        scanf("%d", &n);
    }
    return 0;
}
