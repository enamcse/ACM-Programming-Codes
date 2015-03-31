#include <stdio.h>


int main()
{
    int t, n, cnt, cas=1,i;
    char line[100];//if 89, it works
    scanf("%d", &t);
    while(t--)
    {
        i=cnt = 0;
        scanf("%d", &n);
        scanf("%s", line);
        while(i<n-2)
        {
            if(line[i]=='.')
            {
                line[i+1]=line[i+2] =line[i]= '#';
                cnt++;
                i+=3;
            }
            else i++;
        }
        if(n<2&&line[0]=='.') cnt++;
        else if(line[n-1]=='.'||line[n-2]=='.') cnt++;
        printf("Case %d: %d\n",cas++,cnt);
    }
    return 0;
}
