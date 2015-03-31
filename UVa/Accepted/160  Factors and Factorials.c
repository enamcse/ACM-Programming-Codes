#include <stdio.h>
#include <string.h>

int b[101][25], c[25];

int main()
{
    int i, d, j, k, mod, num=0, a[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    b[2][0] = 1;
    b[3][0] = 1;
    b[3][1] = 1;
    for (i = 4; i <= 100; i++)
    {
        for (k = 0; k<25; k++)
        	b[i][k] = b[i-1][k];
        mod = i;
        while(mod != 1)
        {
            for (j = 0; j < 25; j++)
            {
                if(mod%a[j] == 0)
                {
                    b[i][j]++;
                    mod /= a[j];
                    j = -1;
                }
                if(mod==1) break;
            }
        }
    }

    scanf("%d", &num);

    while(num)
    {
        printf("%3d%c =", num, '!');
        i = 0;
        mod = 0;
        while(1)
        {
            mod++;
            if(mod==16) printf("\n      ");
            printf("%3d", b[num][i++]);
            if(a[i]>num || i == 25) break;
        }
        printf("\n");
        scanf("%d", &num);
    }

    return 0;
}
