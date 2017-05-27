/**
* E:\Dropbox\Code\Others\Habijabis\20160314001.cpp
* Created on: 2016-03-14-14.30.25, Monday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <stdio.h>
int main(void)
{
    char a, b, c;
    int sum, l, i;

    scanf("%d", &l);

    for(i = 1; i <= l; i++)
    {

        scanf("%c %c %c", &a, &b, &c);

        sum = a + b + c;

        printf("%d\n", sum);

    }

    return 0;
}
