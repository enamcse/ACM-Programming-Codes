#include <stdio.h>

void main()

{
    int a, b, c, d, e;

    printf("what is the value of 'a':\n");
    scanf("%d", &a);

    printf("what is the value of 'b':\n");
    scanf("%d", &b);

    d= (a/b)*b;
    e= (a%b);
    c = d+e;

    printf("The value of 'a' is: %d where the division is %d\nAnd the reminder is %d\n",c,d,e);

    return 0;
}
