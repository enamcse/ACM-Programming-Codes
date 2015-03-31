#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i, j, n, count, brac;
    char arr[100], input[5];

    scanf("%d", &n);

    while(n--)
    {
        gets(input);
        count = 0;
        gets(input);
        while(strlen(input) != 0)
        {
            arr[count++] = input[0];
            gets(input);
        }
        arr[count] = '\0';
        brac = 0;
        for (i = 0; i < count; ++i)
        {
            if(arr[i] == '(') ++brac;
        }


    }
    return 0;
}

 if
