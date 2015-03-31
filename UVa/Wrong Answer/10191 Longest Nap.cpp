#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <cstdio>

using namespace std;

struct schedule
{
    int hs;
    int ms;
    int he;
    int me;
};

int main()
{
    schedule work[20];
    char line[300];
    int t, i,caseno=1, max, maxi, diff, hh, mm;
    char ch;

    while(cin>>t)
    {
        max = maxi = 0;
        i = 1;
        cin>>work[0].hs>>ch>>work[0].ms>>work[0].he>>ch>>work[0].me;
        cin.getline(line,280,'\n');

        max = work[0].ms + (60 * (work[0].hs-10));
        maxi = -1;
        while(--t)
        {
            cin>>work[i].hs>>ch>>work[i].ms>>work[i].he>>ch>>work[i].me;
            cin.getline(line,280,'\n');

            if((work[i].hs>10||(work[i].hs==10&&work[i].ms==0))&&((work[i].he<19&&work[i].me==0)||work[i].he<18))
            {
                if(work[i].hs<18)
                {
                    diff = (work[i].ms-work[i-1].me) + (60 * (work[i].hs-work[i-1].he));
                    if(diff>max)
                    {
                        max = diff;
                        maxi = i-1;
                    }
                }
            }
            i++;
        }
        --i;
        diff = (-work[i].me) + (60 * (18-work[i].he));
        if(diff>max)
        {
            max = diff;
            maxi = i;
        }

        hh = max/60;
        mm = max%60;
        if(max==-1)
        {
            if(hh)
            {
                printf("Day #%d: the longest nap starts at 10:00 and will last for %d hours and %d minutes.\n",caseno++,hh,mm);
            }
            else
            {
                printf("Day #%d: the longest nap starts at 10:00 and will last for %d minutes.\n",caseno++,mm);
            }
        }
        else
        {
            if(hh)
            {
                printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d hours and %d minutes.\n",caseno++,work[maxi].he,work[maxi].me,hh,mm);
            }
            else
            {
                printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d minutes.\n",caseno++,work[maxi].he,work[maxi].me,mm);
            }
        }
    }
    return 0;
}
