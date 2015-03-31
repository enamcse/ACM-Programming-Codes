#include <stdio.h>
#include <ctype.h>

#define EOL '\n'

int main()
{
    char letter[80];
    int tag, count;
    while ((letter[0] = getchar()) != '*')
    {
        for (count = 1; (letter[count] = getchar()) != EOL; ++count)
        	;
        tag = count;

        for ( count = 0; count <= tag; ++count)
        	putchar(toupper(letter[count]));
            printf("\n\n");
    }
    printf("Good bye");
    return 0;
}
