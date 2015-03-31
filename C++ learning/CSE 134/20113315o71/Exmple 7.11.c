#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SEED 12345

int throw (void)
{
    double x1, x2;
    int n1, n2;

    x1 = rand() / 32768.0;
    x2 = rand() / 32768.0;

    n1 = 1 + (int)(6 * x1);
    n2 = 1 + (int)(6 * x2);

    return n1 + n2;
}

void play (void)
{
    int score1, score2;
    printf("\nPlease throw the dices . . .");
    getchar();
    printf("\n");

    score1 = throw();
    printf("%2d\n", score1);

    switch (score1)
    {
    case 7:
    case 11:

        printf("Hurra! You have won the game on first throw!!\n:)\n");
        break;

    case 2:
    case 3:
    case 12:

        printf("Sorry! You have lose the game on first throw!!\n:(\n");
        break;

    case 4:
    case 5:
    case 6:
    case 8:
    case 9:
    case 10:

        do
        {
            printf("Throw the dice again . . .\n:|\n");
            getchar();
            score2 = throw();
            printf("%2d\n", score2);
        }
        while (score2 != score1 && score2 != 7);

        if (score2 == score1)
            printf("Hurra! You have won the game by matching your first score!!\n:)\n");
        else
            printf("Sorry! You have lose the game by failling to match your first score!!\n:(\n");
    }
    return;
}

int main()
{
    char answer = 'Y';
    srand(SEED);
    printf("Welcome to the world of CRAPS Shooting . . .\n");
    printf("Press enter to enter the world of CRAPS Shooting . . .\n\n");
    while (toupper(answer) != 'N')
    {
        play();
        printf("Do you want to play again? (Y/N) : ");
        answer = getchar();
        printf("\n");
    }
    printf("See you again in the world of CRABS shooting . . .\n");
    printf("Bye for this time. Have a gloomy day . . .\n");
    return 0;
}
