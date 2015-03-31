#include <stdio.h>
#include <ctype.h>

void sl(float val, int n);
void ddb(float val, int n);
void syd(float val, int n);
void output(int yr, float deprec, float value);

int main()
{
    int n, choice = 0;
    float val;
    char answer1 = 'Y', answer2 = 'Y';

    while (toupper(answer1) != 'N')
    {
        if (toupper(answer2) != 'N')
        {
            printf("\nOriginal value (P): ");
            scanf("%f", &val);
            printf("Number of years (n): ");
            scanf("%d", &n);
        }
        printf("\nMethod: (1-SL 2-DDB 3-SYD) ");
        scanf("%d", &choice);

        switch (choice)
        {
        	case 1:

                printf("\nStraight-Line Method\n\n");
                sl(val, n);
        		break;

            case 2:

                printf("\nDouble-Declining-Balance Method\n\n");
                ddb(val, n);
        		break;

            case 3:

                printf("\nSum-Of-The-Years\'-Digits Method\n\n");
                syd(val, n);
        }
        printf("\n\nAnother calculations? (Y/N) ");
        scanf("%1s", &answer1);
        if (toupper(answer1) != 'N')
        {
            printf("Enter a new set of data? (Y/N) ");
            scanf("%1s", &answer2);
        }
    }

    printf("\nGood Bye. Have a nice day . . .\n");
    return 0;
}
void sl(float val, int n)
{
    float deprec;
    int yr;

    deprec = val / n;
    for (yr = 1; yr <= n; ++yr)
    {
        val-= deprec;
        output(yr, deprec, val);
    }
    return;
}
void ddb(float  val, int n)
{
    float deprec;
    int yr;

    for (yr = 1; yr <= n; ++yr)
    {
        deprec = 2 * val / n;
        val-= deprec;
        output(yr, deprec, val);
    }
    return;
}
void syd(float val, int n)
{
    float deprec, tag;
    int yr;

    tag = val;
    for (yr = 1; yr <= n; ++yr)
    {
        deprec = (n - yr + 1) * tag / (n * (n + 1) / 2);
        val-= deprec;
        output(yr, deprec, val);
    }
    return;
}

void output(int yr, float deprec, float val)
{
    printf("End of Year %2d", yr);
    printf("  Depreciation: %7.2f", deprec);
    printf("  Current Value: %8.2f\n", val);
    return;
}
