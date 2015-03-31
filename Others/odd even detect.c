#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d",&a);

    b=a-((a/10)*10);

        if (a>=0)
            if (b==0||b==2||b==4||b==6||b==8)
                printf("The number %d is even",a);
            else printf("The number %d is odd",a);
        else
        {
            b=-b;

            if (b==0||b==2||b==4||b==6||b==8)
                printf("The number %d is even",a);
            else printf("The number %d is odd",a);
        }
    return 0;
}
