#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, count = 0;
    char action, sk[4];

    while(scanf("%d%c%d%*c%s", &i, &action, &j, sk) == 4)
    {
        if(sk[0] != '?')
        {
            k = atoi(sk);
            if(action == '+' && k == (i+j)) count++;
            else if(action == '-' && k == (i-j)) count++;
        }
    }
    printf("%d\n", count);

    return 0;
}
