#include <stdio.h>

int main()
{
    int n, m;

    scanf("%d", &n);

    while (n>=2)
        {
            m = (n-(n/10)*10);
            if (m==1||m==3||m==5||m==7||m==9)
                {
                    n = 3*n + 1;
                        printf("%d\n",n);
                }
            else
                {
                    n= n/2;
                    printf("%d\n",n);
                }
        }
    printf("STOP\n");
    return 0;
}
