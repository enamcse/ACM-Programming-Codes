#include <stdio.h>
#include <string.h>

int main()
{
    int i, k;
    char ch[100];
    while(gets(ch))
    {
        for (k = 0;k < strlen(ch); k++)
        	ch[k] -= 7;
        puts(ch);
    }
    return 0;
}
