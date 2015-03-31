#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, num[200], n, count = 0, temp, flag;
    char command[3][5] = {"ins", "del", "find"};
    char com[5], quantity[2][4] = {"All", "One"}, compare[4];

    FILE *file1, *file2;
    file1 = fopen("input.txt", "r");
    file2 = fopen("output.txt", "w");

    while (fscanf(file1, " %s %d", com, &n) == 2 && !feof(file1))
    {
        if(strcmpi(command[0], com) == 0)
        {
            num[count++] = n;
            for (i = 0; i < count; ++i)
                for (j = i + 1; j < count; ++j)
                    if(num[i] > num[j])
                    {
                        temp = num[i];
                        num[i] = num[j];
                        num[j] = temp;
                    }
            for (i = 0; i < count; ++i)
                fprintf(file2,"%d ", num[i]);
            fprintf(file2,"\n");
        }
        else if(strcmpi(command[1], com) == 0)
        {
            flag = 1;
            fscanf(file1, " %s ", compare);
            if(strcmpi(compare, quantity[0]) == 0)
            {
                for (i = 0; i < count; ++i)
                    if(num[i] == n)
                    {
                        for (j = i; j < count; ++j)
                        {
                            num[j] = num[j + 1];
                        }
                        --count;
                        flag = 0;
                    }
            }
            else if(strcmpi(compare, quantity[1]) == 0)
            {
                for (i = 0; i < count; ++i)
                    if(num[i] == n)
                    {
                        for (j = i; j < count; ++j)
                        {
                            num[j] = num[j + 1];
                        }
                        --count;
                        flag = 0;
                        break;
                    }
            }

            if (flag) fprintf(file2,"Not Found\n");
            else
            {
                for (i = 0; i < count; ++i)
                    fprintf(file2,"%d ", num[i]);
                fprintf(file2,"\n");
            }

        }
        else if(strcmpi(command[2], com) == 0)
        {
            flag = 1;
            fscanf(file1, " %s ", compare);
            if(strcmpi(compare, quantity[0]) == 0)
            {
                for (i = 0; i < count; ++i)
                    if(num[i] == n)
                    {
                        fprintf(file2,"%d ", i+1);
                        flag = 0;
                    }
                fprintf(file2,"\n");
            }
            else if(strcmpi(compare, quantity[1]) == 0)
            {
                for (i = 0; i < count; ++i)
                    if(num[i] == n)
                    {
                        fprintf(file2,"%d\n", i+1);
                        flag = 0;
                        break;
                    }
            }

            if (flag) fprintf(file2,"Not Found\n");
        }
    }
    fclose(file1);
    fclose(file2);
    return 0;
}
