#include <stdio.h>

void lin_srch (int n);

int main()
{
    char ask;
    int num;
    while (toupper(ask) != 'N')
    {
        printf("How many numbers in the list?\n");
        scanf("%d", &num);
        lin_srch(num);
        printf("\nWant to continue with a new list?   (Y/N)\n");
        scanf(" %c", &ask);
    }
}

void lin_srch (int n)
{
    char ask = 'Y';
    int i, find, numb[1000];

    for (i = 0; i < n; i++)
    	scanf("%d", &numb[i]);

    while (toupper(ask) != 'N')
    {
        int flag = 0, pos;

        printf("\n\nWhat is the number that you want to search? ");
        scanf("%d", &find);

        for (i = 0; i < n; i++)
        	if (find == numb[i])
            {
                flag = 1;
                pos = i + 1;
            }

        if (flag == 1) printf("Number %d is found in the list in position %d\n\n", find, pos);
        else printf("Number %d is not found in the list\n\n", find);

        printf("Find a new number?  (Y/N)\n");
        scanf(" %c", &ask);
    }
}
