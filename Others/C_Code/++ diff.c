#include <stdio.h>

int main()
{
    int i = 5, a = 5;
    printf("%d\n",a);
    a = ++i;
    printf("%d\n",sizeof a);
    return 0;
}
