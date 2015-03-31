#include <stdio.h>

int main()
{
    char text[80];

    scanf("%s", text);

    printf("%s\n", text);
    printf("%.8s\n", text);
    printf("%13.8s\n", text);
    printf("%-13.8s\n", text);

    return 0;
}
