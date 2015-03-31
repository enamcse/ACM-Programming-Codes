#include <stdio.h>
#include <string.h>

int main()
{
    int sub, students, i, j, len;
    double scores[80][10], sum, temp;
    char name[80][20];

    sub = 6;

    printf("\nHow many students\'? ");
    scanf("%d", &students);

    printf("\nPlease enter student name, then enter exam scores (separated by space) for the student.\n");

    for (i = 0; i < students; ++i)
    {
        scanf(" %s", &name[i]);
        for (j = 0; j < 4; ++j)
        {
            scanf("%lf", &temp);
            scores[i][j] = temp * 15 / 100;
        }

        for (j = 4; j < 6; ++j)
        {
            scanf("%lf", &temp);
            scores[i][j] = temp * 20 / 100;
        }
        printf("\n");
    }

    for (i = 0; i < students; ++i)
    {
        sum = 0;
        for (j = 0; j < sub; ++j)
        	sum += scores[i][j];
        scores[i][sub] = sum;
    }

    printf("NAME\t");

    for (i = 0; i <= (sub / 2); ++i)
    	printf("\t");

    printf("EXAM SCORES");

    for (i = i; i <= sub; ++i)
    	printf("\t");

    printf("AVERAGE\n");

    for (i = 0; i < students; ++i)
    {
        printf("%s", name[i]);
        len = strlen(name[i]);

        for (j = 1; j <= (20 - len); ++j)
        	printf(" ");

        for (j = 0; j < sub; ++j)
            printf("%6.2lf  ", scores[i][j]);

        printf("\t%6.2lf", scores[i][sub]);

        printf("\n");
    }

    return 0;
}
