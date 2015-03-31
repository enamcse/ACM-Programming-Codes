#include <stdio.h>
#define SZ 2000000

int arr[SZ], sequence[SZ], num_of_num = 0;

int main()
{
    int i = 0, d, input = 0, flag;
    char ch;
    while(ch != '\n')
    {
        flag = 1;
        scanf("%d%c", &d,&ch);
        for (i = 0; i < input; i++)
            if(sequence[i] == d)
            {
                flag = 0;
                arr[i]++;
                break;
            }
        if(flag)
        {
            sequence[num_of_num] = d;
            ++arr[num_of_num++];
        }
        input++;
    }

    for (i = 0; i < num_of_num; i++)
        printf("%d %d\n", sequence[i], arr[i]);

    return 0;
}
