#include <stdio.h>
#include <string.h>

int main()
{
    int sub, students, i, j, len;
    double scores[80][20], sum, temp, class_avg;
    char name[80][12];

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

    sum = 0;

    for (i = 0; i < students; ++i)
    	sum += scores[i][sub];

    class_avg = sum / students;

    for (i = 0; i < students; ++i)
    	scores[i][sub + 1] = scores[i][sub] - class_avg;


    printf("NAME");

    for (i = 0; i <= (sub / 2); ++i)
    	printf("\t");

    printf("\bEXAM SCORES");

    for (i = i; i <= (sub - 1); ++i)
    	printf("\t");

    printf("     AVERAGE  DEVIATION\n");

    for (i = 0; i < students; ++i)
    {
        printf("%s", name[i]);
        len = strlen(name[i]);

        for (j = 1; j <= (12 - len); ++j)
        	printf(" ");

        for (j = 0; j < sub; ++j)
            printf("%6.2lf  ", scores[i][j]);

        printf(" %6.2lf", scores[i][sub]);

        printf("\t%6.2lf", scores[i][sub + 1]);

        printf("\n");
    }

    printf("\t\t\tThe overall class AVERAGE is %6.2lf\n", class_avg);

    return 0;
}
