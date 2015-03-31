#include<stdio.h>
int main()
{
int l,digit,a,count = 0;
for(l = 1;l <= 10;l++)
{
for(digit = 1;digit <=l;digit++)
{
for(a = digit;a <= digit;a++)
printf("%d ",a);
count++;
if(count > digit)
{
printf("%d",count);
}

}
printf("\n");
}
return 0;
}
