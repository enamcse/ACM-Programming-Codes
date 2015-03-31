#include<stdio.h>

int main()
{
    int n, hh[2], mm[2];

    scanf("%d", &n);

    while(n--)
    {
        scanf("%d:%d", &hh[0], &mm[0]);
        if(hh[0] == 12 && mm[0] == 0)
        {
            hh[1] = 12;
            mm[1] = 0;
        }
        else if(mm[0] == 0)
        {
            hh[1] = 12 - hh[0];
            mm[1] = 0;
        }
        else if(hh[0] == 12)
        {
            hh[1] = 11;
            mm[1] = 60 - mm[0];
        }
        else if(hh[0] == 11)
        {
            hh[1] = 12;
            mm[1] = 60 - mm[0];
        }
        else
        {
            hh[1] = 11 - hh[0];
            mm[1] = 60 - mm[0];
        }

        printf("%02d:%02d\n", hh[1], mm[1]);
    }

    return 0;
}
