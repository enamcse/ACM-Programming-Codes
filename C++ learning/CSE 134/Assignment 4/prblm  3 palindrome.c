#include <stdio.h>

void palindrome (void);

int main()
{
    char ask = 'Y';
    while (toupper(ask) != 'N')
    {
        palindrome();
        printf("Want to check more (Y/N)?\n");
        ask = getchar();
        getchar();
    }

}

void palindrome (void)
{
    int count = 0, i, flag = 0;
    char words[1000], alpha[1000];

    printf("please, write a line and enter to check whether it is palindrome or not.\n");

    for (i = 0; words[i - 1] != '\n'; i++)
    {
        words[i] = getchar();
        if (words[i] != ' ' && words[i] != '\n')
        {
            alpha[count] = words[i];
            count++;
        }
    }

    for (i = 0; i <= (count / 2); i++)
    	if (alpha[i] != alpha[count - i - 1]) flag = 1;

    if (flag == 0) printf("It is a palindrome!!\n\n");
    else printf("It is not a palindrome!!\n\n");
}
