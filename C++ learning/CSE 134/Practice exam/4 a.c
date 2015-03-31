#include <stdio.h>

int main()
{
    int A[25][10];
    printf("%d %d\n", &A, &A[24][9]);
    return 0;
}
