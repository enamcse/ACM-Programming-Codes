#include <stdio.h>
#include <string.h>
#define true 1
#define false 0

int main()
{
    int len, cnt,i,j,x,max, maxpos;
    int list[150];
    int print[150][2];
    char input[5000];
    int flag = false;
    while(gets(input))
    {
        if(flag) printf("\n");
        flag = true;
        cnt = 0;
        max = 1;
        len = strlen(input);

        for (i=32; i<129; i++)
        {
            list[i] = 0;
        }
        for (i=0; i<len; i++)
        {
            x = input[i];
            list[x]++;
        }

        while(max!=0)
        {
            max = 0;
            maxpos = -1;
            for (i=32; i<129; i++)
            {
                if(max<list[i])
                {
                    max = list[i];
                    maxpos = i;
                }
            }
            if(max!=0)
            {
                print[cnt][1] = max;
                print[cnt++][0] = maxpos;
                list[maxpos] = 0;
            }
        }

        for (i = cnt-1; i>=0; i--)
            printf("%d %d\n", print[i][0], print[i][1]);
    }
    return 0;
}
