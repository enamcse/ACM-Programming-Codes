#include <stdio.h>

void ascending(int n, int x[]);
void descending(int n, int x[]);

int main()
{
    int i, n, x[1000];
    printf("How many numbers?   ");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("i = %d    x =   ", i + 1);
        scanf("%d", &x[i]);
    }

    ascending(n, x);

    printf("\n\nSorted list of numbers (Ascending order):\n\n");
    for (i = 0; i < n; i++)
    	printf("i = %d  x = %d\n", i + 1, x[i]);

    descending(n, x);

    printf("\n\nSorted list of numbers (Descending order):\n\n");
    for (i = 0; i < n; i++)
    	printf("i = %d  x = %d\n", i + 1, x[i]);

}

void ascending(int n, int x[])
{
    int i, item, temp;

    for (item = 0; item < (n - 1); ++item)
        for (i = item + 1; i < n; ++i)
        if (x[i] < x[item])
        {
            temp = x[item];
            x[item] = x[i];
            x[i] = temp;
        }
    return;
}

void descending(int n, int x[])
{
    int i, temp;

    for (i = 0; i < ((n / 2) + 1); i++)
    {
        temp = x[n - i - 1];
        x[n - 1 - i] = x[i];
        x[i] = temp;
    }
    return;
}
