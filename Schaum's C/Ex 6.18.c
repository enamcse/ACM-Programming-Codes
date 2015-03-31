#include <stdio.h>

int main()
{
    int n, count, loops, loopcount;
    float x, average, sum;

    printf("How many lists? ");
    scanf("%d", &loops);

    for (loopcount = 1; loopcount <= loops; ++loopcount)
    {
    	sum = 0;
    	printf("\nList number %d\nHow many numbers? ", loopcount);
    	scanf("%d", &n);

    	for ( count = 1; count <= n; ++count)
    	{
    	    printf("x = ");
    	    scanf("%f", &x);
    	    sum += x;
    	}

        average = sum / n;
        printf("\nThe average is %f\n", average);
    }
    return 0;
}
