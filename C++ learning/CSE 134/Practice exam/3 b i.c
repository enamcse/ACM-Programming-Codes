#include <stdio.h>

int main()
{
    int i, j, m, arr[] = {2,5,3,4,3};
    for (i = 0; i < 3; i++)
    	for (j = i; j < 5; j++)
        {
            m = arr[i] % arr[j];
            if(m%5==1) break;
            printf("%d %d %d %d\n", i, j, m, arr[i]*m);
        }
        printf("\n");
    return 0;
}
