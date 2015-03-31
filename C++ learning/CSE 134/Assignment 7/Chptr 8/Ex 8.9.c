/*first file*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SEED 12345

extern void play(void);

int main()
{
    char answer = 'Y';

    printf("Welcome to the Game of CRAPS\n\n");
    printf("To throw the dice, press RETURN\n\n");

    srand(SEED);

    while(toupper(answer) != 'N')
    {
        play();
        printf("\nDo you want to play again? (Y/N) ");
        scanf(" %c", &answer);
        printf("\n");
    }
    printf("Bye, have a nice day");
}

/*second file*/

static int throw_(void);
extern void play(void)
{
    int score1, score2;
    char dummy;

    printf("\nPlease throw the dice . . .");
    scanf("%c", &dummy);
    printf("\n");
    score1 = throw_();
    printf("\n%2d", score1);

    switch (score1)
    {
    case 7:
    case 11:
        printf("    -   Congratulations! You WIN on the first throw\n");
        break;

    case 2:
    case 3:
    case 12:
        printf("    -   Sorry, You LOSE on the first throw\n");
        break;

    case 4:
    case 5:
    case 6:
    case 8:
    case 9:
    case 10:
        do
        {
            printf("    -   Throw the dice again . . .");
            scanf("%c", &dummy);
            score2 = throw_();
            printf("\n%2d", score2);
        }
        while (score2 != score1 && score2 != 7);

        if(score2 == score1)
            printf("    -   You WIN by matching your first score\n");
        else
            printf("    -   You LOSE by failing to match your first score\n");
        break;
    }
    return;
}

static int throw_(void)
{
    float x1, x2;
    int n1, n2;
    x1 = rand() / 32768.0;
    x2 = rand() / 32768.0;

    n1 = 1 + (int) (6 * x1);
    n2 = 1 + (int) (6 * x2);
    return (n1 + n2);
}
