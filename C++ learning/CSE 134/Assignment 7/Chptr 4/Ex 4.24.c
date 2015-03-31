#include <stdio.h>

int main()
{
    char line[12] = {"hexadecimal"};

    printf("%10s %15s %15.5s %.5s\n", line, line, line, line);

    return 0;
}
