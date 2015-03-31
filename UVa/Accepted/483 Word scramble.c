#include<stdio.h>
#include<string.h>

int main()
{
    int i, j;
    char line[100], reverse[100], ch;

    while(scanf("%s", line) == 1)
    {
        ch = getchar();
        for (i = strlen(line) - 1, j = 0; i >= 0; j++, i--)
        {
            reverse[j] = line[i];
        }
        reverse[strlen(line)] = '\0';
        printf("%s", reverse);
        if (ch == ' ') printf(" ");
        else if (ch == '\n') printf("\n");
    }
    return 0;
}

/*#include<stdio.h>
#include<string.h>

int main()
{
    int i, j, l;
    char line[100], reverse[100];

    while(gets(line))
    {
        strcpy(reverse, line);
        for (i = 0, l = 0; i < strlen(line); i++)
        {
            if (line[i] == ' ')
            {
                for (j = l; j < i; j++)
                {
                    reverse[(i - j + l - 1)] = line[j];
                }
                l = i + 1;
            }
            else if (i == (strlen(line) - 1))
            {
                for (j = l; j <= i; j++)
                {
                    reverse[(i - j + l)] = line[j];
                }
                l = i + 1;
            }
        }
        puts(reverse);
    }
    return 0;
}
*/

/* gaurab vai
#include<stdio.h>
#include<string.h>
int main()
{
    char inp[1000],c;
    int i;
    while ( scanf("%s",inp)!=EOF )
    {
        c=getchar();

        for( i=strlen(inp)-1; i>=0; i--)
        {
            printf("%c",inp[i]);
        }
        putchar(c);
    }
    return 0;
}

*/
