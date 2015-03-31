#include<stdio.h>
#include<stdlib.h>

char matrix[3][3];

char check();
void inmatrix();
void pmove();
void cmove();
void dismatrix();

int main()
{
   char done;

   printf("It is a Tic-Tac-Toe Game.\n");
   printf("You will be playing with the computer.\n");

   done=' ';

   inmatrix();

   do
   {
       dismatrix();
       pmove();
       done=check();
       if(done!=' ') break;
       cmove();
       done=check();
   }
   while(done==' ');

   if(done=='X') printf("You won!\n");
   else printf("I won!!!\n");
   dismatrix();

   return 0;
}

void inmatrix()
{
   int i, j;

   for (i=0; i<3; i++)
   {
       for (j=0; j<3; j++)
       {
           matrix[i][j]=' ';
       }
   }
}

void pmove()
{
   int x, y;

   printf("Enter X,Y coordinates for your move: ");
   scanf("%d%*c%d", &x, &y);

   x--;
   y--;

   if(matrix[x][y]!=' ')
   {
       printf("Invalid move, try again.\n");
       pmove();
   }
   else matrix[x][y]='X';

   return;
}

void cmove()
{
   int i, j;
   for (i=0; i<3; i++)
   {
       for (j=0; j<3; j++)
       {
           if(matrix[i][j]==' ') break;
       }
       if(matrix[i][j]==' ') break;
   }
   if(i*j==9)
   {
       printf("Draw!\002");
       exit(0);
   }
   else matrix[i][j]='O';

   return;
}

void dismatrix()
{
   int t;

   for (t=0; t<3; t++)
   {
       printf("%c | %c | %c", matrix[t][0], matrix[t][1], matrix[t][2]);
       if(t!=2) printf("\n--|---|--\n");
   }
   printf("\n");

   return;
}
