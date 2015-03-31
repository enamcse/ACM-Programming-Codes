#include <stdio.h>

int main()
{
    char ch;

    switch (ch = getchar())
    {
        case 'a':
            printf("dog ");
            break;
    case 'b':
        printf("cat ");
    case 'c':
        printf("sakib ");
    case 'd':
        printf("all are same");
    }
    return 0;
}
