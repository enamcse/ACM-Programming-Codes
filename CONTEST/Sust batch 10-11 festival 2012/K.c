#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char str[]);
void itoaa(int n, char s[]);

int main()
{
    int x, y, n;
    char x_con[20], y_con[20];

    scanf("%d", &n);

    while(n--)
    {
        scanf("%d %d", &x, &y);
        itoaa(x, x_con);
        itoaa(y, y_con);
        reverse(x_con);
        reverse(y_con);
        x = atoi(x_con);
        y = atoi(y_con);
        itoaa(x+y, x_con);
        reverse(x_con);
        x = atoi(x_con);

        printf("%d\n", x);
    }

    return 0;
}

void reverse(char str[])
{
    char arr[20];
    int i,n = strlen(str);
    strcpy(arr, str);
    for (i = 0; i < n; ++i)
    	str[i] = arr[n-i-1];
    str[n] = '\0';
    return;
}

void itoaa(int n, char s[])
 {
     int i;
     i = 0;
     do {
         s[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);
     s[i] = '\0';
     reverse(s);
 }
