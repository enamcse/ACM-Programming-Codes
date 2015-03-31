#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, k, data[100], t, temp, flag, flag2;

    char abc[3000];

    scanf("%d", &t);
    for (i = 0; i < t; ++i)
    {
        flag = 1;
        for (j = 0; j < 100; ++j)
            data[j] = 0;
        scanf("%s", abc);

        for (j = 0; j <strlen(abc); ++j)
        {
            temp = abc[j] - 32;
            data[temp]++;
        }

        printf("Case %d: ", i+1);

        for (j = 0; j < 95; ++j)
        {
            flag2 = 1;
            for (k = 2; data[j] > k; ++k)
                if(data[j] % k == 0) flag2 = 0;
            if(flag2 == 1 && data[j] != 0 && data[j] != 1)
            {
                printf("%c", (j + 32));
                flag = 0;
            }
        }

        if(flag) printf("empty");
        printf("\n");
    }

    return 0;
}
