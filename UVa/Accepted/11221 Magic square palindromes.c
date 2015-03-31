#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int i, j, n, count = 1, len, lenth, flag, arr;
    char input[10000], ch;

    scanf("%d ", &n);

    while(n--)
    {
        flag = 0;
        len = 0;
        scanf("%s",input);
        ch = getchar();

        while(ch != '\n')
        {
            arr = strlen(input);
            scanf("%s",&input[arr]);
            ch = getchar();
        }

        len = strlen(input);
        j = 0;
        for (i = 0; i<len; i++)
            if(toupper(input[i]) >= 'A' && toupper(input[i]) <= 'Z') input[j++] = input[i];
        input[j] = '\0';
        len = strlen(input);
        for (i=1; len >= i*i; i++)
            if(i*i == len)
            {
                lenth = i;
                flag = 1;
                break;
            }
        if(flag)
            for (i = 0; i < len/2; i++)
                if(input[i] != input[len - i - 1])
                {
                    flag = 0;
                    break;
                }

        if(flag) printf("Case #%d:\n%d\n", count++, lenth);
        else printf("Case #%d:\nNo magic :(\n", count++);
    }
    return 0;
}
