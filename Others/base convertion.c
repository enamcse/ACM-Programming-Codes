#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numb, base;
    char arr[50];
    printf("number and base: ");
    while(scanf("%d %d", &numb, &base) == 2)
    {
        itoa(numb,arr,base);
    printf("\nThe number %d in base %d is: %s",numb,base,arr);
    printf("\nnumber and base: ");
    }

    return 0;
}
