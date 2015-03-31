#include<stdio.h>

#define SZ 1+3
#define SZ2 2*SZ

int main()
{
    int i, j, n = 6;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j <= 4; j++)
        {
            if(i%((i%j)+1) != 0 && i%((i%j)+1) != 3)
            printf("@ i= %d & j = %d, res= %d\n",i, j, i%((i%j)+1));
        }
    }
    printf("Data = %d\n", i*SZ2*j);
    return 0;
}
