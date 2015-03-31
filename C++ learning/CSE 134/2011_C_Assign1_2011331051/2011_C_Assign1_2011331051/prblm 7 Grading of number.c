#include <stdio.h>

int main()
{
    int marks;

    printf("Marks : ");
    scanf("%d", &marks);

    printf("Grade : ");

    if (marks <= 100)
    {
        if (marks >= 80)
            printf("A+\nCGPA : 4.00\n");
        else if (marks >= 75)
                 printf("A\nCGPA : 3.75\n");
             else if (marks >= 70)
                      printf("A-\nCGPA : 3.50\n");
                  else if (marks >= 65)
                           printf("B+\nCGPA : 3.25\n");
                       else if (marks >= 60)
                                printf("B\nCGPA : 3.00\n");
                            else if (marks >= 55)
                                     printf("B-\nCGPA : 2.75\n");
                                 else if (marks >= 50)
                                          printf("C+\nCGPA : 2.50\n");
                                      else if (marks >= 45)
                                               printf("C\nCGPA : 2.25\n");
                                           else if (marks >= 40)
                                                    printf("C-\nCGPA : 2.00\n");
                                                else printf("F\nCGPA : 0.00\n");
    }
    else printf("Invalid number!\n");

    return 0;
}
