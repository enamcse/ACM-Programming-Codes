#include <stdio.h>

int main()
{
    int marks;

    scanf("%d", &marks);
    printf("Grade : ");

    if (marks > 100 || marks < 0)
        printf("Invalid marks!");
    else if (marks >= 80)
             printf("A+\n");
         else if (marks >= 75)
                  printf("A\n");
              else if (marks >= 70)
                       printf("A-\n");
                   else if (marks >= 65)
                            printf("B+\n");
                        else if (marks >= 60)
                                 printf("B\n");
                             else if (marks >= 55)
                                      printf("B-\n");
                                  else if (marks >= 50)
                                           printf("C+\n");
                                       else if (marks >= 45)
                                                printf("C\n");
                                            else if (marks >= 40)
                                                     printf("C-\n");
                                                 else printf("F\n");

    return 0;
}
