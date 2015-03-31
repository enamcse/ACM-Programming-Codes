#include <stdio.h>
#include <stdlib.h>

int main()
{
    double i;
    char line[20];
    while(scanf("%s", line) == 1)
    {
//        if((line[0] >= '0' && line[0] <= '9') || (line[0] == '.'))
        {
            i = atof(line);
            printf("%lf\n", i);
        }
//        else break;
    }
    return 0;
}
