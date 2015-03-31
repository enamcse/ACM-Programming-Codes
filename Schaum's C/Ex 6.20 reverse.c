#include <stdio.h>

int main()
{
    char line[80];
    int count;

    printf("Enter a line of text below:\n");
    scanf("%[^\n]", line);
    for ( count = 0; line[count]; ++count)
    {
        if (((line[count] > '0') && (line[count] <= '9')) ||
            ((line[count] > 'A') && (line[count] <= 'Z')) ||
            ((line[count] > 'a') && (line[count] <= 'z')))
                putchar(line[count] - 1);
        else if (line[count] == '0') putchar('9');
             else if (line[count] == 'A') putchar('Z');
                  else if (line[count] == 'a') putchar('z');
                       else putchar(' ');
    }
    return 0;
}
