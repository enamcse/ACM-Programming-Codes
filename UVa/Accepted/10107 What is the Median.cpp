#include <stdio.h>
#define sz 10000

int list[sz];

int main()
{
    int a, cnt=0,i,cur, mid, avg;
    while(scanf("%d", &a)==1)
    {
        cur = cnt;

        for (i=0; i<cnt; i++)
        {
            if(list[i]>a)
            {
                cur = i;
                break;
            }
        }
        for (i=cnt; i>=cur; i--)
        {
            list[i+1] = list[i];
        }
        list[cur] = a;
        cnt++;
        if(cnt%2)
        {
            if(cnt==1) printf("%d\n", list[0]);
            else
            {
                mid = cnt>>1;
                printf("%d\n", list[mid]);
            }
        }
        else
        {
            mid = cnt>>1;
            avg = list[mid]+list[mid-1];
            avg>>=1;
            printf("%d\n", avg);
        }
    }
    return 0;
}
