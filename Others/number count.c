#include <stdio.h>

int main()
{
    int count = 0;
    char* ch;
    FILE* pi;

    pi = fopen("c:\\Users\Enam Pagla\Desktop\pi.txt","r");
    fgets(ch, 2000, pi);

    ch = getchar();
    while (1)
    {


       // if (ch >= '0' && ch <= '9') count++;

        //if (ch == '*') break;

        printf("%d ", count++);
    }

    printf("Number of number is : %d", count);
    return 0;
}
