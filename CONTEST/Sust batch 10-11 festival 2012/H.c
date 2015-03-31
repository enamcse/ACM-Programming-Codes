#include <stdio.h>
#include <string.h>
#define SZ 26
#define falsee '0'
#define truee '1'

typedef struct
{
    int x;
    int y;
} coordinate;

int main()
{
    int i=0, j=0, front, rare, max,len, a, b, n, count, ii;
    coordinate Q[625], node;
    char grid[SZ][SZ], color[SZ][SZ];

    scanf("%d", &n);

    while(n--)
    {
        front = rare = max = a = b = 0;
        scanf(" %s", grid[0]);
        len = strlen(grid[0]);
        for (i = 1; i < len; ++i)
        {
            scanf(" %s", grid[i]);
        }

        for (i=0; i<len; ++i)
            for (j=0; j<len; ++j)
                color[i][j] = falsee;

        for (a=0; a<len; ++a)
            for (b=0; b<len; ++b)
            {
                if(color[a][b] == falsee)
                {
                    count = 0;
                    color[a][b] = truee;
                    Q[rare].x = b;
                    Q[rare++].y = a;
                    while(front<rare)
                    {
                        node.x = Q[front].x;
                        node.y = Q[front++].y;
                        if(grid[node.x][node.y] == truee)
                        {
                            grid[node.x][node.y] = falsee;
                            for (i=node.y-1; i <= node.y+1; ++i)
                            {
                                for (j=node.x-1; j <= node.x+1; ++j)
                                {
                                    if(i>=0 && j>=0 && i<len && j<len && grid[i][j] == truee)
                                    {
                                        count++;
                                        grid[i][j] = falsee;
                                        color[i][j] = truee;
                                        Q[rare].x = j;
                                        Q[rare++].y = i;

                                        for (ii = 0; ii < len; ++ii)
                                        {
                                            printf("::%s:::%s::\n", color[ii], grid[ii]);
                                        }
                                        printf(":i=%d:j=%d::x=%d:y=%d::%d=LL\n\n",i,j, node.x, node.y, count);
                                    }
                                }
                            }
                        }
                    }
                    if(count>max) max = count;

                    printf("::%d::\n", count);
                }
            }

        printf("max = %d\n", max);
        for (i = 0; i < len; ++i)
        {
            printf("::%s::\n", color[i]);
        }
    }
    return 0;
}
