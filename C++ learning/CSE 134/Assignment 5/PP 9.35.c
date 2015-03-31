#include <stdio.h>
#include <math.h>

#define SIZE 100

void reorder_s_to_l_by_magnitude (int n, float x[]);
void reorder_l_to_s_by_magnitude (int n, float x[]);
void reorder_s_to_l_algebric (int n, float x[]);
void reorder_l_to_s_algebric (int n, float x[]);

int main()
{
    int i, n, choice;
    float x[SIZE];
    printf("\nHow many number will be entered? ");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; ++i)
    {
        printf("i = %d  x = ", i + 1);
        scanf("%f", &x[i]);
    }

    printf("\nWhat type of rearrengement do you want to do?\n\
(Enter your choice number from the list below)\n\
           1    -   Smallest to largest, by magnitude\n\
           2    -   Largest to Smallest, by magnitude\n\
           3    -   Smallest to largest, algebric (by sign)\n\
           4    -   Largest to Smallest, algebric (by sign)\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        reorder_s_to_l_by_magnitude (n, x);
        break;

    case 2:
        reorder_l_to_s_by_magnitude (n, x);
        break;

    case 3:
        reorder_s_to_l_algebric (n, x);
        break;

    case 4:
        reorder_l_to_s_algebric (n, x);
        break;
    }

    printf("\n\nReordered List of Numbers:\n\n");
    for (i = 0; i < n; ++i)
        printf("i = %d x = %.2f\n", i + 1, x[i]);
}

void reorder_s_to_l_by_magnitude (int n, float x[])

{
    int i, item;
    float temp;

    for (item = 0; item < n - 1; ++item)
        for (i = item + 1; i < n; ++i)
            if (fabs(x[i]) < fabs(x[item]))
            {
                temp = x[item];
                x[item] = x[i];
                x[i] = temp;
            }
}

void reorder_l_to_s_by_magnitude (int n, float x[])
{
    int i, item;
    float temp;

    for (item = 0; item < n - 1; ++item)
        for (i = item + 1; i < n; ++i)
            if (fabs(x[i]) > fabs(x[item]))
            {
                temp = x[item];
                x[item] = x[i];
                x[i] = temp;
            }
}

void reorder_s_to_l_algebric (int n, float x[])
{
    int i, item;
    float temp;

    for (item = 0; item < n - 1; ++item)
        for (i = item + 1; i < n; ++i)
            if (x[i] < x[item])
            {
                temp = x[item];
                x[item] = x[i];
                x[i] = temp;
            }
}

void reorder_l_to_s_algebric (int n, float x[])
{
   int i, item;
    float temp;

    for (item = 0; item < n - 1; ++item)
        for (i = item + 1; i < n; ++i)
            if (x[i] > x[item])
            {
                temp = x[item];
                x[item] = x[i];
                x[i] = temp;
            }
}
