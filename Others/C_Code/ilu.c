#include <stdio.h>
#include <conio.h>

int main()
{
    char x;

    printf("Janu,Do you love me?\nIf yes, please press the key '1' then enter!\n");
    scanf("%c",&x);

    if (x=='1')
    {
        char x=3;
        printf("\nI also %c you Janu!!\n",x);
        printf("Many many %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c for you\nThank you!!\n",x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x);
    }

    else printf("Stupid!!\nYou didn't press 3!");

    getch();

    return 0;
}
