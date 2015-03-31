#include <stdio.h>
#include <string.h>

int main()
{
    int count = 0, flag = 0, i = 0, j, k, end;
    char line[100];

    scanf("%s", &line[0]);
    k = strlen(line);

    while (i < k)
    {
        flag = 0;
        count = 0;
        while (toupper(line[i]) >= 'A' && toupper(line[i]) <= 'Z')
        {
            end = i;
            count++;
            ++i;
            flag = 1;
        }

        if (flag == 1)
            for (j = end; j > (end - count); j--)
                printf("%c", line[j]);
        else printf("%c", line[i++]);
    }
    return 0;
}
