#include <stdio.h>

int main()
{
    int n, m, i=0, j=0, k=1,l=0,p;
    FILE *file1, *file2;
    file1 = fopen("input.txt", "r+");
    file2 = fopen("output.txt", "w+");

    while(fscanf(file1, "%d %d", &n, &m)==2)
    {
        if(n==m)
        {
            for (i = 0; i<n; i++)
                fprintf(file2,"BG");
        }
        else if(n>m)
        {
            for (i = 0; i<m; i++)
                fprintf(file2,"BG");
            p = n - m;
            for (i = 0; i<p; i++)
                fprintf(file2,"B");
        }
        else
        {
            for (i = 0; i<n; i++)
                fprintf(file2,"BG");
            p = m - n;
            for (i = 0; i<p; i++)
                fprintf(file2,"G");
        }

        fprintf(file2,"\n");
    }
    fclose(file1);
    fclose(file2);
    return 0;
}
