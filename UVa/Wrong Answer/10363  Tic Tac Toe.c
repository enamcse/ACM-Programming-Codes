#include <stdio.h>
#include <string.h>
#define p_1 'X'
#define p_2 'O'
#define check(x,y)  if (grid[0] == x && grid[4] == x && grid[8] == x) y = 1;        \
                    else if (grid[0] == x && grid[1] == x && grid[2] == x) y = 1;   \
                    else if (grid[3] == x && grid[4] == x && grid[5] == x) y = 1;   \
                    else if (grid[6] == x && grid[7] == x && grid[8] == x) y = 1;   \
                    else if (grid[0] == x && grid[3] == x && grid[6] == x) y = 1;   \
                    else if (grid[1] == x && grid[4] == x && grid[7] == x) y = 1;   \
                    else if (grid[2] == x && grid[5] == x && grid[8] == x) y = 1;   \
                    else if (grid[1] == x && grid[4] == x && grid[7] == x) y = 1;   \
                    else if (grid[2] == x && grid[4] == x && grid[6] == x) y = 1;   \
                    else y = 0;

int n;

int main()
{
    int i, p1, p2, flag1, flag2;
    char grid[9];

    scanf("%d", &n);

    while(n--)
    {
        p1 = p2 = flag1 = flag2 = 0;
        printf("%d ", n);
        for (i = 0; i < 3; i++)
        	scanf("%s", &grid[3*i]);
        printf("%d %s\n", n, grid);
        for (i = 0; i < 9; i++)
        {
            if(grid[i] == p_1) p1++;
            else if (grid[i] == p_2) p2++;
        }

        check(p_1,flag1)
        check(p_2,flag2)

        if(flag1 && flag2) printf("no\n");
        else if(p1>=p2) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
