#include <stdio.h>

#define SIZE 80

int x[SIZE], y[SIZE];

int compare(const void *a, const void *b);

int main()
{
    int n, i;

    printf("How many points? : ");
    scanf("%d", &n);

    for (i = 0; i < n; ++i)
    {
        printf("\n%2d. (x, y) : ", i+1);
        scanf("%d %d", &x[i], &y[i]);
    }

    qsort(x, n, sizeof(int), compare);

    for (i = 0; i < n; ++i)
    {
        printf("(%d, %d)\n", x[i], y[i]);
    }

    return 0;
}

int compare(const void *a, const void *b)
{
    int *po1, *po2, *temp;
    int *p = (int *) a;
    int *q = (int *) b;
    if (*p - *q >= 0)
    {
       po1 = p - &x + &y;
       po2 = q - &x + &y;
       temp = po1;
       po1 = po2;
       po2 = temp;
    }
    return *p - *q;`
}
