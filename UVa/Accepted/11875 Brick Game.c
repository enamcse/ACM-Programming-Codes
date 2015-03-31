#include <stdio.h>

int main()
{
    int a[10], t, n, i, j, temp, k;

    scanf("%d", &t);

    for (i = 0; i < t; ++i)
    {
        scanf("%d", &n);
        for (j = 0; j < n; ++j)
        	scanf("%d", &a[j]);

        for (j = 0; j < n - 1; ++j)
            for (k = j + 1; k < n; ++k)
                if(a[j] < a[k])
                {
                    temp = a[j];
                    a[j] = a[k];
                    a[k] = temp;
                }

        if(n == 3) printf("Case %d: %d\n",i+1, a[1]);
        else if (n == 5) printf("Case %d: %d\n",i+1, a[2]);
        else if (n == 7) printf("Case %d: %d\n",i+1, a[3]);
        else if (n == 9) printf("Case %d: %d\n",i+1, a[4]);
    }


    return 0;
}
