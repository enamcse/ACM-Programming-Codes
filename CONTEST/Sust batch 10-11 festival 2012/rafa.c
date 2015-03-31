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

int bfs(int len, char grid[SZ][SZ], char color[SZ][SZ], coordinate node);

int main()
{
    int i=0, j=0, front, rare, max,len, a, b, n, count, ii, jj;
    coordinate node;
    char grid[SZ][SZ], color[SZ][SZ];

    scanf("%d", &n);

    while(n--)
    {
        max = 0;
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
                    color[a][b] = truee;
                    if(grid[a][b] == truee)
                    {
                        node.x = a;
                        node.y = b;
                        count = bfs(len,grid,color,node);
                        if(count>max) max = count;
                    }


                    for (ii = 0; ii < len; ++ii)
                    {
                        printf("S::");
                        for (jj = 0; jj < len; ++jj)
                        {
                            printf("%c", color[ii][jj]);
                        }
                        printf(":::");
                        for (jj = 0; jj < len; ++jj)
                        {
                            printf("%c",grid[ii][jj]);
                        }
                        printf("::\n");
                    }
                    printf(":i=%d:j=%d::x=%d:y=%d::%d=LL\n\n",i,j, node.x, node.y, count);

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


int bfs(int len, char grid[SZ][SZ], char color[SZ][SZ], coordinate node)
{
    int count = 0, front = 0, rare = 0, i, j, ii, jj, flag, m, n;
    coordinate Q[625];
    Q[rare].x = node.x;
    Q[rare++].y = node.y;
    while(front<rare)
    {
        node.x = Q[front].x;
        node.y = Q[front++].y;
        printf("ffffffff %d rrrrrrr %d\n", node.x, node.y);
        if(grid[node.y][node.x] == truee)
        {
            grid[node.y][node.x] = falsee;
            count++;
            for (i=node.y-1; i <= node.y+1; ++i)
            {
                for (j=node.x-1; j <= node.x+1; ++j)
                {
                    if(i>=0 && j>=0 && i<len && j<len && grid[i][j] == truee)
                    {
                        flag = 1;
                        for (m=front; m<=rare; ++m)
                        {
                            if(Q[m].x == j && Q[m].y == i)
                            {
                                flag = 0;
                            }
                        }
                        if(flag)
                        {
                            count++;
                            color[i][j] = truee;
                            Q[rare].x = j;
                            Q[rare++].y = i;
                        }
                        else color[i][j] = truee;

                    }
                    else if (i>=0 && j>=0 && i<len && j<len)
                    {
                        color[i][j] = truee;
                    }

                    printf("front = %d, rare = %d:i=%d:j=%d::x=%d:y=%d::%d=LL\n\n",front, rare, i,j, node.x, node.y, count);
                    //else if (i>=0 && j>=0 && i<len && j<len)color[i][j] = truee;
                    /*for (ii = 0; ii < len; ++ii)
                    {
                        printf("::");
                        for (jj = 0; jj < len; ++jj)
                        {
                            printf("%c", color[ii][jj]);
                        }
                        printf(":::");
                        for (jj = 0; jj < len; ++jj)
                        {
                            printf("%c",grid[ii][jj]);
                        }
                        printf("::\n");
                    }
                    printf("front = %d, rare = %d:i=%d:j=%d::x=%d:y=%d::%d=LL\n\n",front, rare, i,j, node.x, node.y, count);*/
                }
            }
        }
    }
    return count;
}
