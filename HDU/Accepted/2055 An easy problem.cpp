#include<stdio.h>
int main()
{
    int n,t;
    char ch,c;
    scanf("%d ",&t);
    while(t--)
    {
        scanf("%c %d ",&ch,&n);
//printf("%c %d\n", ch, n);
        if(ch>='A'&&ch<='Z') printf("%d\n",((ch-'A'+1)+n));
        if(ch>='a'&&ch<='z') printf("%d\n",(-(ch-'a'+1)+n));
    }
    return 0;
}
