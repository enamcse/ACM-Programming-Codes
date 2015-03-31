#include <stdio.h>

int main()
{
    int present, total_class, i = 0, stdnt_no = 1;
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
        printf("Student id no. %d : present in  %d classes (out of %d classes)\n", stdnt_no++, present, total_class);
    }
    return 0;
}
