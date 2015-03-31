#include <stdio.h>
#include <ctype.h>

int main()
{
    char c, pig[] = "ay", cons;
    while(scanf("%c", &c)==1)
    {
        if(toupper(c)=='A'||toupper(c)=='E'||toupper(c)=='I'||toupper(c)=='O'||toupper(c)=='U')
        {
            printf("%c", c);
            scanf("%c", &c);
            while(toupper(c)>='A'&&toupper(c)<='Z')
            {
                printf("%c", c);
                scanf("%c", &c);
            }
            printf("%s%c", pig, c);
        }
        else if(toupper(c)>='A'&&toupper(c)<='Z')
        {
            cons = c;
            scanf("%c", &c);
            while(toupper(c)>='A'&&toupper(c)<='Z')
            {
                printf("%c", c);
                scanf("%c", &c);
            }
            printf("%c%s%c", cons, pig, c);
        }
        else printf("%c", c);
    }
    return 0;
}
