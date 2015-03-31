#include <stdio.h>

int main()
{
    int i = 12345, j = 0xabcd9, k = 077777;

    printf("%d %x %o\n", i, j, k);
    printf("%3d %3x %3o\n", i, j, k);
    printf("%8d %8x %8o\n", i, j, k);
    printf("%-8d %-8x %-8o\n", i, j, k);
    printf("%+8d %+8x %+8o\n", i, j, k);
    printf("%08d %#8x %#8o\n", i, j, k);

    return 0;
}
