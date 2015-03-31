#include <stdio.h>

void sorting(int n, int x[]);
void binary_srch (int y, int find, int x[]);

int main()
{
    int i, n, x[1000], find;
    char ask = 'Y';
    printf("How many numbers?   ");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("i = %d    x =   ", i + 1);
        scanf("%d", &x[i]);
    }

    sorting(n, x);



    while (toupper(ask) != 'N')
    {
        printf("\n\nWhat is the number that you want to search? ");
        scanf("%d", &find);
        binary_srch(n - 1, find, x);
        printf("Find a new number?  (Y/N)\n");
        scanf(" %c", &ask);
    }
}

void sorting(int n, int x[])
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

    printf("\n\nSorted list of numbers (Ascending order):\n\n");
    for (i = 0; i < n; i++)
        printf("i = %d  x = %d\n", i + 1, x[i]);
    return;
}

void binary_srch (int y, int find, int x[])
{
    int z = 0;



    while(1)
    {
        if (find > x[y] || find < x[z])
        {
            printf("The number %d is not in the list\n\n", find);
            break;
        }
        if (find <= x[y/2] && find >= x[z]) y = y / 2;
        else if (find > x[y/2] && find >= x[z])
        {
            if ((y + z) % 2 == 1) z = (y + z) / 2 + 1;
            else z = (y + z) / 2;
        }


        printf("%d  %d  %d  %d\n", y, x[y], z, x[z]);

        if (find == x[y] || find == x[z])
        {
            printf("The number %d is in the list\n\n", find);
            break;
        }
        else if (y == z && find != x[y])
        {
            printf("The number %d is not in the list\n\n", find);
            break;
        }
    }
}
