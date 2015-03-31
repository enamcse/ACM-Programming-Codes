#include<stdio.h>
#include<string.h>
#include <ctype.h>

int main()
{
    int i, j, num, len, no[130], highest;
    char input[250];

    while(gets(input))
    {
        highest = 0;
        for (i = 0; i<130; i++)
        	no[i] = 0;
        len = strlen(input);
        for (i = 0; i<len; i++)
        {
            if(toupper(input[i]) >= 'A' && toupper(input[i]) <= 'Z')
            {
                num = input[i];
                no[num]++;
            }
        }

        for (i = 0; i<130; i++)
        	if(highest < no[i]) highest = no[i];

        for (i = 0; i<130; i++)
        	if(highest == no[i]) printf("%c", i);

        printf(" %d\n", highest);
    }

    return 0;
}
