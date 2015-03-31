#include <iostream>
#include <cstdio>
#include <cstring>

int main()
{
    int n, i, count, k;
    char arr[300], check[300];

    scanf("%d ", &n);

    while(n--)
    {
        count = 0;
        gets(arr);
        k = strlen(arr);
        i = 0;

        while(i < k)
        {
            if(arr[i] == '(')
                check[count++] = arr[i];
            else if(arr[i] == '[')
                check[count++] = arr[i];
            else if(arr[i] == ')')
            {
                if(i > 0 && check[count - 1] == '(') --count;
                else check[count++] = arr[i];
            }
            else if(arr[i] == ']')
            {
                if(i > 0 && check[count - 1] == '[') --count;
                else check[count++] = arr[i];
            }
            ++i;
        }
        if(count != 0) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
