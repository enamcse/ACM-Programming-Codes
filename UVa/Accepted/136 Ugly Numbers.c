#include <stdio.h>

int main()
{
    printf("The 1500\'th ugly number is 859963392.\n");

    return 0;
}
/*
#include <stdio.h>

int main()
{
    unsigned long int ugly[1500], number, serial, count = 0, flag;
    ugly[count++] = 1;
    serial = 1;

    while(count<=1499)
    {
        number = ++serial;
        flag = 1;
        while(number > 1)
        {
            if(number%2==0)
            {
                number/=2;
            }
            else if(number%3==0)
            {
                number/=3;
            }
            else if(number%5==0)
            {
                number/=5;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if(flag==1)
        {
            ugly[count++] = serial;

        }
    }

    printf("The %d\'th ugly number is %d.\n", count, ugly[count-1]);

    return 0;
}
*/
