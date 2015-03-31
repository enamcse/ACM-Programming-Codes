#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int i, j, n, len1, len2, flag;
    char a[40][20];

    scanf("%d", &n);

    for (i = 0; i < (2 * n); i += 2)
    {
        scanf("%s %s", a[i], a[i + 1]);
        len1 = strlen(a[i]);
        len2 = strlen(a[i + 1]);

        if (len1 == len2)
        {
            flag = 1;
            for (j = 0; j < len1; ++j)
            {
                if(a[i][j] != a[i + 1][j])
                {
                    if (tolower(a[i][j]) == 'a' || tolower(a[i][j]) == 'e' || tolower(a[i][j]) == 'i' ||
                        tolower(a[i][j]) == 'o' || tolower(a[i][j]) == 'u')
                    {
                        if (tolower(a[i + 1][j]) != 'a' && tolower(a[i + 1][j]) != 'e' && tolower(a[i + 1][j]) != 'i' &&
                            tolower(a[i + 1][j]) != 'o' && tolower(a[i + 1][j]) != 'u') flag = 0;
                    }
                    else flag = 0;
                }
            }
            if (flag == 1) printf("Yes\n");
            else printf("No\n");
        }
        else printf("No\n");
    }
    return 0;
}
