#include <stdio.h>
#include <string.h>

int main()
{
    char ch[1000];
    int i;

    while(gets(ch))
    {
        for (i = 0; i < strlen(ch); ++i)
        {
            if(ch[i] == 'W') ch[i] = 'Q';
            else if(ch[i] == 'E') ch[i] = 'W';
            else if(ch[i] == 'R') ch[i] = 'E';
            else if(ch[i] == 'T') ch[i] = 'R';
            else if(ch[i] == 'Y') ch[i] = 'T';
            else if(ch[i] == 'U') ch[i] = 'Y';
            else if(ch[i] == 'I') ch[i] = 'U';
            else if(ch[i] == 'O') ch[i] = 'I';
            else if(ch[i] == 'P') ch[i] = 'O';
            else if(ch[i] == '[') ch[i] = 'P';
            else if(ch[i] == ']') ch[i] = '[';
            else if(ch[i] == '\\') ch[i] = ']';
            else if(ch[i] == 'S') ch[i] = 'A';
            else if(ch[i] == 'D') ch[i] = 'S';
            else if(ch[i] == 'F') ch[i] = 'D';
            else if(ch[i] == 'G') ch[i] = 'F';
            else if(ch[i] == 'H') ch[i] = 'G';
            else if(ch[i] == 'J') ch[i] = 'H';
            else if(ch[i] == 'K') ch[i] = 'J';
            else if(ch[i] == 'L') ch[i] = 'K';
            else if(ch[i] == ';') ch[i] = 'L';
            else if(ch[i] == '\'') ch[i] = ';';
            else if(ch[i] == 'X') ch[i] = 'Z';
            else if(ch[i] == 'C') ch[i] = 'X';
            else if(ch[i] == 'V') ch[i] = 'C';
            else if(ch[i] == 'B') ch[i] = 'V';
            else if(ch[i] == 'N') ch[i] = 'B';
            else if(ch[i] == 'M') ch[i] = 'N';
            else if(ch[i] == ',') ch[i] = 'M';
            else if(ch[i] == '.') ch[i] = ',';
            else if(ch[i] == '/') ch[i] = '.';
            else if(ch[i] == '2') ch[i] = '1';
            else if(ch[i] == '3') ch[i] = '2';
            else if(ch[i] == '4') ch[i] = '3';
            else if(ch[i] == '5') ch[i] = '4';
            else if(ch[i] == '6') ch[i] = '5';
            else if(ch[i] == '7') ch[i] = '6';
            else if(ch[i] == '8') ch[i] = '7';
            else if(ch[i] == '9') ch[i] = '8';
            else if(ch[i] == '0') ch[i] = '9';
            else if(ch[i] == '-') ch[i] = '0';
            else if(ch[i] == '=') ch[i] = '-';
        }
        puts(ch);
    }
    return 0;
}
