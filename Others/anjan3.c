#include<stdio.h>
#include<math.h>

int main()
{
int i,rem,sum;
sum=0;
scanf("%d",&i);
for(;i>0||i<0;)
{
rem=abs(i%10);
i=abs(i/10);
sum=sum+rem;
}
printf("The sum of number's digits is : %d",sum);
return 0;
}
