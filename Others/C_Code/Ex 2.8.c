#include <stdio.h>
int main()
{
    char about;
    about = 'b'*'49';
    printf("what i\0s\b\b%c?", about);
    return 0;
}
