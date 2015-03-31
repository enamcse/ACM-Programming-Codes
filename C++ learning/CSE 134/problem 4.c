#include <stdio.h>

int main()
{
    int count = 0;
    char ch;
    ch = getchar();

    while (ch != '\n')
    {

        while (((ch >= 65 && ch <= 90) || (ch >= 97 && ch <=122))&& ch != '\n')
        {
            ch = getchar();
        }

        /*if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <=122)) count++;
        if ((ch < 65 && ch > 90) || (ch < 97 && ch > 122)) count--;*/
        if (ch != '\n') ch = getchar();
    }

    printf("The number of word is %d", count);
    return 0;
}
