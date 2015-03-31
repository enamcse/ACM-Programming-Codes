#include<stdio.h>

int main()
{
    int mat[4][3],i,j;

    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }

    printf("\n");

    for(j=0;j<3;j++)
    {
        for(i=0;i<4;i++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
