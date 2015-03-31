#include <stdio.h>
#include <string.h>

int main()
{
    int i, k;
    char ch[25];

    while (gets(ch))
    {
        ch[24] =' ';
        for (i = 0; i < strlen(ch); ++i)
        {
            if(i == 0) k = 24;
            else k = i - 1;

            if((ch[i] == 'B' || ch[i] == 'F' || ch[i] == 'P' || ch[i] == 'V') &&
                ch[k] != 'B' && ch[k] != 'F' && ch[k] != 'P' && ch[k] != 'V') printf("%d", 1);
            else if((ch[i] == 'C' || ch[i] == 'G' || ch[i] == 'J' || ch[i] == 'K' ||
                    ch[i] == 'Q' || ch[i] == 'S' || ch[i] == 'X' || ch[i] == 'Z') &&
                    ch[k] != 'C' && ch[k] != 'G' && ch[k] != 'J' && ch[k] != 'K' &&
                    ch[k] != 'Q' && ch[k] != 'S' && ch[k] != 'X' && ch[k] != 'Z') printf("%d", 2);
            else if((ch[i] == 'D' || ch[i] == 'T') && ch[k] != 'D' && ch[k] != 'T') printf("%d", 3);
            else if(ch[i] == 'L' && ch[k] != 'L') printf("%d", 4);
            else if((ch[i] == 'M' || ch[i] == 'N') && ch[k] != 'M' && ch[k] != 'N') printf("%d", 5);
            else if(ch[i] == 'R' && ch[k] != 'R') printf("%d", 6);
        }
        printf("\n");
    }
    return 0;
}
