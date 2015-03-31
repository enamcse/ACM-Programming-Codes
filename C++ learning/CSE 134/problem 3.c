#include <stdio.h>

int main()
{
    int vow = 0, cons = 0;
    char ch;

    ch = getchar();

    while (ch != '\n')
    {
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        vow++;
        else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) cons++;

        ch = getchar();
    }

    printf("Vowel :     %d\nConsonant : %d", vow, cons);

    return 0;
}
