#include <stdio.h>

int main()
{
    int x[80], y[80], n, i, j, temp[2];

    printf("How many points? : ");
    scanf("%d", &n);

    for (i = 0; i < n; ++i)
    {
        printf("\n%2d. (x, y) : ", i+1);
        scanf("%d %d", &x[i], &y[i]);
    }

    for (i = 0; i < n - 1; ++i)
    	for (j = i + 1; j < n; ++j)
    		if(x[i] > x[j])
    		{
    		    temp[0] = x[i];
    		    temp[1] = y[i];
    		    x[i] = x[j];
    		    y[i] = y[j];
    		    x[j] = temp[0];
    		    y[j] = temp[1];
    		}
    		else if(x[i] == x[j] && y[i] > y[j])
    		{
    		    temp[0] = x[i];
    		    temp[1] = y[i];
    		    x[i] = x[j];
    		    y[i] = y[j];
    		    x[j] = temp[0];
    		    y[j] = temp[1];
    		}

    for (i = 0; i < n; ++i)
    {
        printf("(%d, %d)\n", x[i], y[i]);
    }

    return 0;
}
