#include <stdio.h>

int main()
{
    int hh[2], mm[2], time2sleep;

    scanf("%d %d %d %d", &hh[0], &mm[0], &hh[1], &mm[1]);

    while(hh[0] != 0 || hh[1] != 0 || mm[0] != 0 || mm[1] != 0)
    {
        if(hh[0] == hh[1] && mm[1] > mm[0]) time2sleep = mm[1] - mm[0];
        else if (hh[0] == hh[1] && mm[1] == mm[0]) time2sleep = 1440;
        else if (hh[0] == hh[1] && mm[1] < mm[0]) time2sleep = 1440 - mm[0] + mm[1];
        else
        {
            time2sleep = 60 - mm[0];
            hh[0]++;
            if(hh[0] == 24) hh[0] = 0;
            while(hh[0] != hh[1])
            {
                time2sleep += 60;
                hh[0]++;
                if(hh[0] == 24) hh[0] = 0;
            }
            time2sleep += mm[1];
        }
        printf("%d\n", time2sleep);

        scanf("%d %d %d %d", &hh[0], &mm[0], &hh[1], &mm[1]);
    }

    return 0;
}
