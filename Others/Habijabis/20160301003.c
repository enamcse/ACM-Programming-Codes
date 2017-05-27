/**
* E:\Dropbox\Code\Others\Habijabis\20160301003.c
* Created on: 2016-03-01-14.37.59, Tuesday
* Verdict: Not Solved
* Author: Enamul Hassan
**/
#include <stdio.h>
int main()
{
    char a[100],b[100];
    char string[100];
    int c;
    printf("Type your first word: ");
    gets(a);
    printf("Type your 2nd name: ");
    gets(b);
    c=str_concat(a,b);
    int ntp=str_len(a,b);
    printf("\n");
    printf("String: %s and Len is %d\n",c,ntp);


    return 0;
}

int str_concat(char a[100],char b[100])
{
    int i,j,m=0;

    for(i=0;a[i]!='\0';i++)
    {
        m++;
    }

    for(i=m,j=0;b[j]!='\0';i++,j++)
    {
        a[i]=b[j];
    }

    a[i]='\0';

    return a;
}

int str_len(char a[100],char b[100])
{
    int i,j,m=0;

    for(i=0;a[i]!='\0';i++)
    {
        m++;
    }

    return m;
}
