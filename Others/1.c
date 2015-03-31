#include <stdio.h>
#include <stdlib.h>

#define swap *(a + i)^=*(a + item)^=*(a + i)^=*(a + i)^*(a + item);

int main()
{
    long n, i, item, temp;
    int *a;
    scanf("%ld", &n);

    while (n != 0)
    {
        a = (int *) malloc(n * sizeof(int));
        for (i = 0; i < n; ++i)
            scanf("%d", (a + i));

        for (item = 0; item < n - 1; ++item)
            for (i = item + 1; i < n; ++i)
                if (*(a + i) < *(a + item) && *(a + i) != *(a + item)) swap
                else if (*(a + i) < *(a + item))
                {
                    temp = *(a + item);
                    *(a + item) = *(a + i);
                    *(a + i) = temp;
                }

        for (i = 0; i < n; ++i)
            printf("%d ", *(a + i));

        printf("\n");
        scanf("%ld", &n);
    }
    return 0;
}
