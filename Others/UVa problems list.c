#include <stdio.h>

int main()
{
    int i, j, no[100], rank[100];
    char name[100][100], garbage[100];
    FILE *file1;

    file1 = fopen("C:\\Users\\smart\\Desktop\\UVa.out", "a");

    fgets(garbage, 1, file1);

    for(i = 0; fscanf(file1, " %d %s %d", &no[i], name[i], &rank[i]) != EOF; i++);

    printf("%5s\t%-40s\t%7s\n", "PRBLM#", "\t\tPROBLEM DESCRIPTION", "RANK#");

    for(; scanf(" %d %s %d", &no[i], name[i], &rank[i]) && name[i][0] != '*'; i++) ;

    fprintf(file1, "%5s\t%-40s\t%7s\n", "PRBLM#", "\t\tPROBLEM DESCRIPTION", "RANK#");

    for(j = 0; j < i; ++j) fprintf(file1, "%5d\t%-40s\t%7d\n", no[j], name[j], rank[j]);

    fclose(file1);

    return 0;
}
