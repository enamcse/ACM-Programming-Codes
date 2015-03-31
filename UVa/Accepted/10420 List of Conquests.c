#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char country[20];
    int count;
} data;

int compare(data *elem1, data *elem2);

int main()
{
    data info[2005];
    int i, j, count = 0, n, flag;
    char country[20], input[100];

    scanf("%d ", &n);
    for(i = 0; i < n; i++)
    {
        gets(input);
        flag = 1;
        sscanf(input, "%s", country);
        if(i != 0)
        {
            for (j = 0; j < count; ++j)
            {
                if(strcmp(country, info[j].country) == 0)
                {
                    flag = 0;
                    info[j].count++;
                    break;
                }
            }
            if(flag == 1)
            {
                strcpy(info[count].country, country);
                info[count++].count = 1;
            }
        }
        else
        {
            strcpy(info[count].country, country);
            info[count++].count = 1;
        }
    }

    qsort(info, count, sizeof(data), compare);

    for (i = 0; i < count; ++i)
    {
        printf("%s %d\n", info[i].country, info[i].count);
    }


    return 0;
}

int compare(data *elem1, data *elem2)
{
    return strcmp(elem1->country,elem2->country);
}
