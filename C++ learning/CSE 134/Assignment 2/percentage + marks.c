#include <stdio.h>

int main()
{
    int present, total_class, i = 0, stdnt_no = 1, marks;
    double percent, present_f;
    char ch;

    printf("Total classes : ");
    scanf("%d", &total_class);

    while (1)
    {
        present = 0;
        i = 0;

        printf("\nStudent id no. %d : ", stdnt_no);

        while (i < total_class)
        {
            ch = getchar();

            if (ch == 'P' || ch == 'p')
            {
                present++;
                i++;
            }
            else if (ch == 'A' || ch == 'a') i++;
        }

        present_f = present;
        percent = 100 * present_f / total_class;

        if (percent >= 95) marks = 10;
        else if (percent >= 90) marks = 9;
        else if (percent >= 85) marks = 8;
        else if (percent >= 80) marks = 7;
        else if (percent >= 75) marks = 6;
        else if (percent >= 70) marks = 5;
        else if (percent >= 95) marks = 4;
        else if (percent >= 60) marks = 3;
        else if (percent < 60) marks = 0;

        printf("Student id no. %d :\n                Present in : %d classes (out of %d classes)\n", stdnt_no++, present, total_class);
        printf("                Percentage of attendence : %lf\n                Marks on attendence : %d", percent, marks);
    }
    return 0;
}
