#include <stdio.h>

int main()
{
    int a, b, i= 0, n;

    scanf("%d", &n);

    while (i < n)
    {
        scanf("%d %d", &a, &b);

        if (a > b) printf(">\n");
        else if (a < b) printf("<\n");
             else printf("=\n");
        i++;
    }
    return 0;
}
