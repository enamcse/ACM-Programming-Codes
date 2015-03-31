#include <stdio.h>

int main()
{
    char ch;
    int vow = 0, cons = 0;

    ch = getchar();

    while (ch !='\n')
    {
        if (ch == 65 || ch == 69 || ch == 73 || ch == 79 || ch == 85) vow = vow++;
        else if (ch == 97 || ch == 101 || ch == 105 || ch == 111 || ch == 117) vow++;
             else if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) cons = cons++;

        ch = getchar();
    }

    printf("Numbers of Vowel is : %d\nNumbers of Consonant is : %d\n", vow, cons);

    return 0;
}
