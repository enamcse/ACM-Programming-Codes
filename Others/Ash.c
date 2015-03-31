#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SEED 12345

void play(void);
int throw_(void);
main()
{
    char answer='Y';
    printf("Welcome to the game of CRAPS\n\n");
    printf("To throw the dice , press ENTER\n\n");
    srand(SEED);
    while(toupper(answer) != 'N')
    {
        play();
        printf("\nDo you want to play again? (Y/N)");
        scanf("%c", &answer);
        printf("\n");
    }
    printf("Bye have a nice day");
}
void play(void)
{
    int score1, score2;
    char Dummy;

    printf("\nplease throw the dice......");
    scanf("%c", &Dummy);
    printf("\n");
    score1=throw_();
    printf("%2d", score1);

    switch(score1)
    {
    case 7:
    case 11:
    {
        printf("congratulations, you win the first throw\n");
        break;
    }
    case 2:
    case 3:
    case 12:
    {
        printf("sorry you lose on the first throw\n");
        break;
    }
    case 4:
    case 5:
    case 6:
    case 8:
    case 9:
    case 10:

        do
        {
            printf("Throw the dice again....");
            scanf("%c", &Dummy);
            score2=throw_();
            printf("\n%2d", score2);
        }
        while(score2 != score1 && score2 !=7);
        {
            if(score2==score1)
                printf("you win by matching your first score");
            else
                printf("you lose by failing to match your first score");
            break;
        }
        return ;
    }
}
int throw_(void)
{
    float x1,x2;
    int n1,n2;
    x1=rand()/32768.0;
    x2=rand()/32768.0;
    n1=1+(int) (6*x1);
    n2=1+(int) (6*x2);
    return (n1+n2);
}

