#include <stdio.h>

int main()
{
    int n;
    printf("Hello Sazzad!\nHow are you?\nWhat do you want to do?\n");
    printf("Press 1 then enter for Sleeping.\nPress 2 then enter for eating.\nPress 3 then enter for studying.\nPress 4 then enter for Taltibaltiying.\n");
    scanf("%d", &n);

    if (n == 1) printf("Have a good dream...\nGood Bye...\n:)");
    else if (n == 2) printf("Health is the most valuable things in the world...\nSo, dont be late to take fresh food...\nGood Bye...\n:)");
         else if (n == 3) printf("Study is the only things to survive in the world...\nSo, study attentively...\nGood Bye...\n:)");
              else if ( n == 4) printf("Dont do Tatibalti...\nCoz, life is very short...\nGood Bye...\n:)");
                else printf("Oh! you typed unestimated number...\nHave a good day...\nGood Bye...\n:)");
    return 0;
}
