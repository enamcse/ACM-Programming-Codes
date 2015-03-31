#include <stdio.h>
#include <string.h>

char str[1000];
int stk[1000];

int main()
{
    int top,i,value;

    while(scanf(" %[^\n]",str)==1)
    {
        top = 0;
        value = 0;
        for(i = 0; str[i]!='\0' ; i++)
        {
            if(str[i]>='0' && str[i]<='9')
                stk[++top] = str[i]-'0';
            else if(str[i]=='+')
            {
                stk[top-1] = stk[top-1] + stk[top];
                top--;
            }
            else if(str[i]=='-')
            {
                stk[top-1] = stk[top-1] - stk[top];
                top--;
            }
            else if(str[i]=='*')
            {
                stk[top-1] = stk[top-1] * stk[top];
                top--;
            }
            else if(str[i]=='/')
            {
                stk[top-1] = stk[top-1] / stk[top];
                top--;
            }
        }
        printf("value = %d\n",stk[top]);
    }
    return 0;
}
