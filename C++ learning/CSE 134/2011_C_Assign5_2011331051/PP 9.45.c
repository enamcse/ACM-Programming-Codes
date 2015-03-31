#include <stdio.h>

int main()
{
    int i, cur_1, cur_2, exit = 1;
    double currency[] = {0.65, 1.4, 1.7, 5.3, 1.5, 1570, 98, 3.4, 1.3, 1}, converter;
    char country[][25] = {{"British pound"}, {"Canadian dollar"},{"Dutch guilder"},{"French frane"},{"German mark"},
        {"Italian lira"},{"Japanese yen"},{"Mexican peso"},{"Swiss franc"}, {"U.S. dollar"}};

    do
    {
        printf("Enter the first currency number from the list below:\n");

        for (i = 0; i < 10; i++)
        {
            printf("\n\t");
            printf("%2d - %s", i + 1, country[i]);
        }
        printf("\n");
        scanf("%d", &cur_1);

        for (i = 0; i < 10; i++)
        {
            printf("\n\t");
            printf("%d - %s", i + 1, country[i]);
        }

        printf("\n");
        scanf("%d", &cur_2);


        converter = currency[cur_2 - 1] / currency[cur_1 - 1];
        printf("\n\n%s %.2lf is equivalent to one %s.\n\n\n", country[cur_2 - 1], converter, country[cur_1 - 1]);

        printf("Press 0 to exit and 1 to continue.\n");
        scanf("%d", &exit);

    }
    while(exit != 0);

    return 0;
}
