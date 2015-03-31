#include <stdio.h>

int main()
{
    int x[20][30];

    x[0][0] = 0xF;
    x[2][0] = 0xFF;
    x[2][5] = 0xFFF;
    x[0][5] = 0xFFFF;

    printf("x = %X\n", x);
    printf("x[0][0] = %X\n", x[0][0]);
    printf("x + 2 = %X\n", (x + 2));
    printf("x[0][0] + 2 = %X\n", (x[0][0] + 2));
    printf("*(x + 2) = %X\n", (*(x + 2)));
    //printf("*(x[0][0] + 2) = %X\n", (*(x[0][0] + 2)));
    printf("*(x + 2) + 5 = %X\n", (*(x + 2) + 5));
    //printf("*(x[0][0] + 2) + 5 = %X\n", (*(x[0][0] + 2) + 5));
    printf("*(*(x + 2) + 5) = %X\n", *(*(x + 2) + 5));
    //printf("*(*(x[0][0] + 2) + 5) = %X\n", *(*(x[0][0] + 2) + 5));

    return 0;
}
