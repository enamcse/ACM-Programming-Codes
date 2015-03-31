#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char big[105]="", input[105],compare[105], end[] = "E-N-D", len;
    int i, n, j;
    scanf(" %s",input);
//    printf("%s\n",input);
    while(strcmp(end,input)!=0)
    {
        len = strlen(input);
        for(i=0,j=0; i<len; i++)
        {
            if((toupper(input[i])>='A' && toupper(input[i])<='Z')||input[i] == '-')
            {
                compare[j++] = input[i];
            }
            else
            {
                compare[j] = '\0';
                j=0;
                if(strlen(big) < strlen(compare))
                {
                    strcpy(big,compare);

                }
                if(i+1<len) continue;
                else break;
            }
        }

        if(i==len)
        {
            compare[j] = '\0';
            if(strlen(big) < strlen(compare))
            {
                strcpy(big,compare);

            }
        }

        scanf(" %s",input);
//        printf("%s\n",input);
    }

    len = strlen(big);
    for(i=0; i<len; i++)
    {
        printf("%c",tolower(big[i]));
    }
    printf("\n");

    return 0;
}
