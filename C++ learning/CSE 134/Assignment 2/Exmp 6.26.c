#include <stdio.h>

int main()
{
    int n, year, choice;
    float val, tag, deprec;

    while (choice != 4)
    {
        printf("\Method: (1-SL  2-DDB  3-SYD 4-End) ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 3)
        {
            printf("Original value: ");
            scanf("%f", &val);
            printf("Numbers of years: ");
            scanf("%d", &n);
        }

        switch (choice)
        {
        case 1:

            printf("\nStraight-Line Method\n\n");
            deprec = val / n;
            for (year = 1; year <= n; ++year)
            {
                val -= deprec;
                printf("End of Year %2d", year);
                printf("    Depreciation: %7.2f", deprec);
                printf("    Current Value: %8.2f\n", val);
            }
            break;

        case 2:

            printf("\nDouble-Declining-Balance Method\n\n");

            for (year = 1; year <= n; ++year)
            {
                deprec = 2 * val / n;
                val -= deprec;
                printf("End of Year %2d", year);
                printf("    Depreciation: %7.2f", deprec);
                printf("    Current Value: %8.2f\n", val);
            }
            break;

        case 3:

            printf("\nSum-Of-The-Years\'-Digits Method\n\n");
            tag = val;
            for (year = 1; year <= n; ++year)
            {
                deprec = (n - year +1) * tag / (n * (n + 10 / 2));
                val -= deprec;
                printf("End of Year %2d", year);
                printf("    Depreciation: %7.2f", deprec);
                printf("    Current Value: %8.2f\n", val);
            }
            break;

        case 4:

            printf("\nGoodbye, have a nice day!\n");
            break;

        default:
            printf("\nIncorrect data entry  please try again\n");
        }
    }
    return 0;
}
