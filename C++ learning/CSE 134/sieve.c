#include <stdio.h>

#define SZ 100000005

char sieve[SZ];

int main()
{
    register int i, j;
    int k,n,l;

//    FILE *file1;
//
//    file1 = fopen("Sieve.out", "w");

//    scanf("%d", &n);
    n=100000000;
    for (i = 3; (k=i*i)<=n; i += 2)
    {
        if(sieve[i] == 0)
        {
            l=i << 1;
            for (j = k; j <= n; j += l)
            {
                sieve[j] = 1;
            }
        }
    }

//    fprintf(file1,"%d", 2);
//
//    for (i = 3; i <= n; i += 2)
//    {
//        if(sieve[i] == 0) fprintf(file1,",\n%d", i);
//    }
//
//    fclose(file1);

    return 0;
}
