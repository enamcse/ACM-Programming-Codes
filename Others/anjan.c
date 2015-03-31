#include<stdio.h>
main()
{
int numb,mod,z;
z=0;
scanf("%d",&numb);
for( ;numb>=0; )
{
mod=numb%10;
numb=numb/10;
z=z+mod;
}
printf("%d",z);
}
