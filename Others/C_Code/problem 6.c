#include <stdio.h>

int main()
{
    int n = 2, numb, mod;

    printf("Type your number: \n");
    scanf("%d", &numb);

    if (numb <= 1) printf("Not ");
    else if (n<numb)
        {
            while (n<numb)
            {
                mod = numb % n;

                if (mod == 0)
                {
                    printf("Not ");
                    n = numb;
                }
                else ;
                n++;
            }
        }

    printf("Prime\n");
    return 0;
}
