#include <stdio.h>

int main()
{
    int i;
    char c, line[80];

    printf("Please enter a line of text below:\n");
    for(i = 0; (c = getchar()) !='\n'; ++i)
        line[i] = c;

    for (--i; i >= 0; --i)
    	printf("%c", line[i]);
    return 0;
}
