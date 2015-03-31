#include <stdio.h>

char upper_to_lower (char ch);

int main()
{
    char upper;
    printf("Please enter an uppercase line then enter : ");
    while(upper = getchar())
    {
        if (upper == '\n') break;
        putchar(upper_to_lower(upper));
    }
    return 0;
}

char upper_to_lower (char ch)
{
    char ch1;
    ch1 = (ch >= 'A' && ch <= 'Z') ? ch -'A' + 'a' : ch;
    return ch1;
}
