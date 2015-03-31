#include <stdio.h>
#include <string.h>

int main()
{
    int i, n = 1, flag;
    char a[15], b[][15] =
    {
        {"HELLO"},
        {"HOLA"},
        {"HALLO"},
        {"BONJOUR"},
        {"CIAO"},
        {"ZDRAVSTVUJTE"},
    };
    char lang[][15] =
    {
        {"ENGLISH"},
        {"SPANISH"},
        {"GERMAN"},
        {"FRENCH"},
        {"ITALIAN"},
        {"RUSSIAN"},
        {"UNKNOWN"},
    };

    while(strlen(gets(a)) != 1 || a[0] != '#')
    {
        flag = 1;

        for (i = 0; i < 6; i++)
            if(strcmp(a,b[i]) == 0)
            {
                printf("Case %d: %s\n", n++, lang[i]);
                flag = 0;
            }
        if (flag) printf("Case %d: %s\n", n++, lang[i]);
    }
    return 0;
}
