#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SZ 5000

int main()
{
    char input[SZ];

    while(gets(input))
    {
        int len;
        len = strlen(input);
        for (int i = 0; i < len; ++i)
        {
            if(input[i] == ']') input[i] = 'p';
            else if(input[i] == '[') input[i] = 'o';
            else if(tolower(input[i]) == 'p') input[i] = 'i';
            else if(tolower(input[i]) == 'o') input[i] = 'u';
            else if(tolower(input[i]) == 'i') input[i] = 'y';
            else if(tolower(input[i]) == 'u') input[i] = 't';
            else if(tolower(input[i]) == 'y') input[i] = 'r';
            else if(tolower(input[i]) == 't') input[i] = 'e';
            else if(tolower(input[i]) == 'r') input[i] = 'w';
            else if(tolower(input[i]) == 'e') input[i] = 'q';
            else if(tolower(input[i]) == 'w') input[i] = ']';
            else if(tolower(input[i]) == 'q') input[i] = '[';
            else if(tolower(input[i]) == '\\') input[i] = ';';
            else if(tolower(input[i]) == '\'') input[i] = 'l';
            else if(tolower(input[i]) == ';') input[i] = 'k';
            else if(tolower(input[i]) == 'l') input[i] = 'j';
            else if(tolower(input[i]) == 'k') input[i] = 'h';
            else if(tolower(input[i]) == 'j') input[i] = 'g';
            else if(tolower(input[i]) == 'h') input[i] = 'f';
            else if(tolower(input[i]) == 'g') input[i] = 'd';
            else if(tolower(input[i]) == 'f') input[i] = 's';
            else if(tolower(input[i]) == 'd') input[i] = 'a';
            else if(tolower(input[i]) == 's') input[i] = '\\';
            else if(tolower(input[i]) == 'a') input[i] = '\'';
            else if(tolower(input[i]) == '/') input[i] = ',';
            else if(tolower(input[i]) == '.') input[i] = 'm';
            else if(tolower(input[i]) == ',') input[i] = 'n';
            else if(tolower(input[i]) == 'm') input[i] = 'b';
            else if(tolower(input[i]) == 'n') input[i] = 'v';
            else if(tolower(input[i]) == 'b') input[i] = 'c';
            else if(tolower(input[i]) == 'v') input[i] = 'x';
            else if(tolower(input[i]) == 'c') input[i] = 'z';
            else if(tolower(input[i]) == 'x') input[i] = '/';
            else if(tolower(input[i]) == 'z') input[i] = '.';
            else if(tolower(input[i]) == '=') input[i] = '0';
            else if(tolower(input[i]) == '-') input[i] = '9';
            else if(tolower(input[i]) == '0') input[i] = '8';
            else if(tolower(input[i]) == '9') input[i] = '7';
            else if(tolower(input[i]) == '8') input[i] = '6';
            else if(tolower(input[i]) == '7') input[i] = '5';
            else if(tolower(input[i]) == '6') input[i] = '4';
            else if(tolower(input[i]) == '5') input[i] = '3';
            else if(tolower(input[i]) == '4') input[i] = '2';
            else if(tolower(input[i]) == '3') input[i] = '1';
            else if(tolower(input[i]) == '2') input[i] = '=';
            else if(tolower(input[i]) == '1') input[i] = '-';
            else if(tolower(input[i]) == '`') input[i] = '0';
        }
        puts(input);
    }

    return 0;
}
