#include <stdio.h>

int main()
{
    int i, j, k, a[80], b[80], n;
    printf("How many numbers?");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    	scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    	scanf("%d", &b[i]);
    for (i = 0; i < n; i++)
    	printf("%d ", a[i] + b[n-1-i]);
    return 0;
}
