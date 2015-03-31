#include <stdio.h>
#include <ctype.h>

void sl(float val, int n);
void ddb(float val, int n);
void syd(float val, int n);
void writeoutput(int year, float depreciation, float value);

int main()
{
    int n, choice = 0;
    float val;
    char answer1 = 'Y', answer2 = 'Y';

    while (toupper(answer1) != 'N')
    {
        if (toupper(answer2) != 'N')
        {
            printf("\nOriginal value: ");
            scanf("%f", &val);
            printf("Number of years: ");
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
            break;
        }

        printf("\n\nAnother calculation? (Y/N) ");
        scanf("%1s",&answer);
        if (toupper(answer1) != 'N')
        {
            pritnf("Enter a new set of data? (Y/N) ");
            scanf("%1s", &answer2);
        }
    }

    printf("\nGood bye, have a nice day!\n");
}
