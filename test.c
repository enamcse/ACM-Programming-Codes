#include <stdio.h>
#include <stdlib.h>

int main() {
    int len=300;
	char a[len+5], b[len+5], res[len+5];
	int carry=0,sum,i;

	for( i = 0; i<len; i++)
	{
		a[i] = '0' + (rand()%10);
		b[i] = '0' + (rand()%10);
	}
	a[len]=0;
	b[len]=0;
    res[len]=0;
	for(i = len-1; i>=0; i--)
	{
		sum = (a[i]-'0')+(b[i]-'0')+carry;
		carry = sum/10;
		res[i]='0'+(sum%10);
	}
	if(carry)
	{
		for(i = len;i>=0;i--)
		{
			res[i+1]=res[i];
		}
		res[0]='1';
	}

	printf("%s\n +\n%s\n =\n%s\n", a, b, res);

	return 0;
}
