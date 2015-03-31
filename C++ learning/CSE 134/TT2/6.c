#include <stdio.h>

struct{
    int roll;
    char name[20];
    double cgpa;
} student[10];

int main()
{
    FILE *file1;

    file1 = fopen("Input.in", "r+");

    int i;
    for (i = 0; i < 10; i++)
    fscanf(file1, "%d %s %lf", &student[i].roll, student[i].name, &student[i].cgpa);
    fclose(file1);

    for (i = 0; i < 10; i++)
    printf("%d %s %.2lf\n", student[i].roll, student[i].name, student[i].cgpa);

    return 0;
}
