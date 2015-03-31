#include <stdio.h>
#include <string.h>

int main() {

    double price[] = {0.0,4.0,4.5,5.0,2.0,1.5};
    int i, j;
    scanf("%d %d", &i, &j);

    printf("Total: R$ %.2lf\n", price[i]*j);

    return 0;
}
