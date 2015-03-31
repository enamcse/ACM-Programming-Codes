#include <stdio.h>

int main()
{
    int a, ld;
    printf("What is your desired,you want to see the last digit of the, number?");
    scanf("%d",&a);
    ld=a-((a/10)*10);
    {
        if (ld >=0 )
    printf("The last digit of the number is:%d\n",ld);
    else ld=-ld;
    printf("The last digit of the number is:%d\n",ld);
    }
    return 0;
}
