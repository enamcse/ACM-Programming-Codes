#include <stdio.h>
#include <string.h>

int main()
{
    int n, i;
    char numb[5];

    scanf("%d", &n);

    for (i = 0; i < n; ++i)
    {
        scanf("%s", numb);
        if(strlen(numb) == 5) printf("3\n");
        else if(numb[0] == 'o' && (numb[1] == 'n' || numb[2] == 'e')) printf("1\n");
        else if(numb[0] == 't' && (numb[1] == 'w' || numb[2] == 'o')) printf("2\n");
        else if(numb[0] != 'o' && numb[1] == 'n' && numb[2] == 'e') printf("1\n");
        else if(numb[0] != 't' && numb[1] == 'w' && numb[2] == 'o') printf("2\n");
    }
    return 0;
}
