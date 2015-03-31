#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SEED 12345

void play (void);
int throw (void);

int main()
{
    char answer = 'Y';

    printf("Welcome to the Kingdom of CRAPS . . .\n\n");
    printf("To throw the dice, press enter key . . .\n\n");

    srand(SEED);

    while (toupper(answer) != 'N')
    {
        play();
        printf("Do you want to play again? (Y/N) ");
        scanf("%c", &answer);
        printf("\n");
    }
    printf("Good Bye from the Kingdom of CRAPS, See you again here soon.");
    return 0;
}

void play (void)
{
    int score1, score2;

    printf("\nPress enter to throw the dice . . .");
    getchar();
    printf("\n");
    score1 = throw();
    printf("\n%2d", score1);

    switch (score1)
    {
    	case 7:
    	case 11:

    	printf(" - Hurra!! You have won the game on first throw . . .\n     :)\n");
    		break;

        case 2:
    	case 3:
    	case 12:

    	printf(" - Sorry! You have lost the game on first throw . . .\n     :(\n");
    		break;

    	case 4:
    	case 5:
    	case 6:
    	case 8:
    	case 9:
    	case 10:

    	do
    	{
    	    printf(" - Throw the dice again . . .");
    	    getchar();
    	    score2 = throw();
            printf("\n%2d", score2);
    	}
    	while (score2 != score1 && score2 != 7);

    	if (score1 == score2)
            printf(" - Hurra!! You have won the game by matching your first score . . .\n     :)\n");
        else
            printf(" - Sorry! You have lost the game by failing to match your first score . . .\n     :(\n");
        break;
    }

    return;
}

int throw (void)
{
    float x1, x2;
    int n1, n2;

    x1 = rand() /32768.0;
    x2 = rand() /32768.0;

    n1 = 1 + (int) (6 * x1);
    n2 = 1 + (int) (6 * x2);

    return n1 + n2;
}
