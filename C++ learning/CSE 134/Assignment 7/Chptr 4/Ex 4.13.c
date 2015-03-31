#include <stdio.h>

int main()
{
    char item[20] = {"Welcome!"};
    int partno;
    float cost;

    partno = 25;
    cost = 25.36;

    scanf("%s %*d %f", item, &cost);
    printf("%s %d %f\n", item, partno, cost);

    return 0;
}
