#include <stdio.h>

void multiply(int matrix[20][20], int matrix1[20][20], int matrix2[20][20], int row1, int col1, int row2, int col2);

int main()
{
    int col1, row1, col2, row2, i, j;
    int matrix1[20][20], matrix2[20][20], matrix[20][20];
    printf("Enter the number of rows and columns (m, n) of 1st matrix: \n");

    while(scanf("%d %d", &row1, &col1) == 2)
    {
        printf("Enter the 1st matrix: \n");
        for(i = 0; i < row1; i++)
            for(j = 0; j < col1; j++)
                scanf("%d", &matrix1[i][j]);

        printf("Enter the number of rows and columns (m, n) of 2nd matrix: \n");
        scanf("%d %d", &row2, &col2);

        printf("Enter the 2nd matrix: \n");
        for(i=0; i<row2; i++)
            for(j = 0; j < col2; j++)
                scanf("%d", &matrix2[i][j]);

        if(row2 != col1)
            printf("Invalid input for column and row!\n");
        else
        {
            multiply(matrix, matrix1, matrix2, row1, col1, row2, col2);

            printf("Result: \n\n");
            for(i = 0; i < row1; i++)
            {
                for(j = 0; j < col2; j++)
                    printf("%d ", matrix[i][j]);
                printf("\n");
            }
        }
        printf("Enter the number of rows and columns (m, n) of 1st matrix: \n");
    }
}

void multiply(int matrix[20][20], int matrix1[20][20], int matrix2[20][20], int row1, int col1, int row2, int col2)
{
    int i, j, k;
    for(i = 0; i < row1; i++)
        for(j = 0; j < col2; j++)
            matrix[i][j] = 0;

    for(i = 0; i < row1; i++)
        for(j = 0; j < col2; j++)
            for(k = 0; k < row1; k++)
                matrix[i][j] += matrix1[j][k] * matrix2[k][i];
    return;
}
