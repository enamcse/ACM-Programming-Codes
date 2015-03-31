#include <stdio.h>

void abv_avg(int n);

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    	abv_avg(n);
}

void abv_avg(int n)
{
    float numb[1000], sum = 0, avg;
    int i, flag = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%f", &numb[i]);
        sum += numb[i];
    }

    avg = sum / n;
    printf("Average =   %f\n", avg);
    printf("The numbers above average are:\n\n", avg);

    for (i = 0; i < n; i++)
    	if (numb[i] > avg)
    	{
    	    printf("%.3f\n", numb[i]);
    	    flag = 1;
    	}

    if (flag == 0) printf("None!\n");
    		return;
}
