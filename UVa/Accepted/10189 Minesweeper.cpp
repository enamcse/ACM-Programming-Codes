#include <stdio.h>
#define sz 150

int graph[sz][sz];
char input[sz][sz];

int main()
{
    int caseno=1, i, j, k, m, n, p, q;
    bool flag=false;
    scanf("%d %d", &m, &n);
    while(m&&n)
    {
        for (i=0; i<m; i++)
            for (j=0; j<n; j++)
                graph[i][j] = 0;

        for (i=0; i<m; i++)
        {
            getchar();
            for (j=0; j<n; j++)
                scanf("%c", &input[i][j]);

        }
//        printf("\n");

        for (i=0; i<m; i++)
        {
            for (j=0; j<n; j++)
            {
                if(input[i][j]=='*')
                {
                    for (p = i-1; p<=(i+1); p++)
                    {
                        for (q = j-1; q<=j+1; q++)
                        {
                            if(p>=0&&q>=0)
                            {
                                ++graph[p][q];
                            }
                        }
                    }
                }
            }
        }
        printf("Field #%d:\n", caseno++);
        for (i=0; i<m; i++)
        {
            for (j=0; j<n; j++)
            {
                if(input[i][j] == '*') printf("*");
                else printf("%d", graph[i][j]);
            }
            printf("\n");
        }
        scanf("%d %d", &m, &n);
        if(m&&n) printf("\n");
    }
    return 0;
}
/*
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0
*/
