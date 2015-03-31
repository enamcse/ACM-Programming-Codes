
#include <stdio.h>
#include <string.h>

void push(int a);
int pop();

char str[1000];
int stk[1000];
int top;

int main()
{
    int i,value, a, b, c;

    while(scanf(" %[^\n]",str)==1)
    {
        top = 0;
        value = 0;
        for(i = 0; str[i]!='\0' ; i++)
        {
            if(str[i]>='0' && str[i]<='9')
                push(str[i]-'0');
            else if(str[i]=='+')
            {
                a = pop();
                b = pop();
                c = a + b;
                push(c);
            }
            else if(str[i]=='-')
            {
                b = pop();
                a = pop();
                c = a - b;
                push(c);
            }
            else if(str[i]=='*')
            {
                a = pop();
                b = pop();
                c = a * b;
                push(c);
            }
            else if(str[i]=='/')
            {
                b = pop();
                a = pop();
                c = a / b;
                push(c);
            }
        }
        printf("value = %d\n",stk[top]);
    }
    return 0;
}

void push(int a)
{
    stk[++top] = a;
    return;
}

int pop()
{
    return stk[top--];
}
