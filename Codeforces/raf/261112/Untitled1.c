#include<stdio.h>
insertionsort(int a[],int n);
main()
{ int a[20],i,j,k,n;

printf("Enter the number of array=");
scanf("%d",&n);
printf("Enter the %d numbers\n");
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
printf("before the insertion sort:");
{
    for(i=1;i<=n;i++)
scanf("%d",&a[i]);
}
insertionsort(a,n);
}
insertionsort(inta[],int n)
 {
     int i,j,k;
 for(j=1;j<=n;j++)
    {
        k=a[j];
 i=j-1;
 while(i>-1&&a[i]>k)
 {
     a[i+1]=a[i]
 i=i-1;
      }
      a[i+1]=k;

 }
 printf("\n\n After insertion sort:");
 for(i=1;i<=n;i++)
    {
        printf("%d",a[i-1]);

    }

 }


