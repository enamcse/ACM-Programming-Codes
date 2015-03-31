/*
ID: manetsus
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <string.h>
#define fread freopen("gift1.in","r",stdin)
#define fwrite freopen("gift1.out","w",stdout)
int main()
{
    int i, j, k, l, n, person, amount, money[20], devide, flag, u = 0;
    char names[20][15], name[15], ch;
    fread;
    fwrite;
    while(scanf("%d", &n) == 1)
    {
        if(u++) printf("\n");
        ch = getchar();
        for (i = 0; i < n; ++i)
        {
            scanf("%s", names[i]);
            ch = getchar();
            money[i] = 0;
        }

        for (i = 0; i < n; ++i)
        {
            scanf("%s", name);
            ch = getchar();
            flag = 0;
            for (j = 0; j < n; ++j)
            {
                if(strcmp(name, names[j]) == 0)
                {
                    flag = 1;
                    scanf("%d %d",&amount, &person);
                    ch = getchar();
                    if(person == 0 && amount != 0) break;
                    else if(amount || person)
                    {
                        devide = amount/person;
                        money[j]-= (devide * person);
                        for (k = 0; k < person; ++k)
                        {
                            scanf("%s", name);
                            ch = getchar();
                            for(l=0; l< n; ++l)
                            {
                                if(strcmp(name, names[l]) == 0)
                                {
                                    money[l]+= devide;
                                    break;
                                }
                            }
                        }
                    }
                }
                if(flag) break;
            }
        }
        for (i = 0; i < n; ++i)
        {
            printf("%s %d\n", names[i], money[i]);
        }
    }
    return 0;
}
