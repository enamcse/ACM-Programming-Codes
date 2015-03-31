#include<stdio.h>

int main()
{
int i,rem,sum;
sum=0;
scanf("%d",&i);
for(;i>0;)
{
rem=i%10;
i=i/10;
sum=sum+rem;
}

printf("The sum of number's digits is : %d",sum);
return 0;
}
