#include <stdio.h>
#include <string.h>

int main()
{
    char a[20000];
    int b;
    gets(a);
    b = strlen(a);
    printf("%d\n", b);
    return 0;
}
