#include <stdio.h>
#include <string.h>

int main()
{
    char  __7[50000];
    while(scanf("%s", __7) == 1)
        printf("%d\n", strlen(__7));
    return 0;
}
