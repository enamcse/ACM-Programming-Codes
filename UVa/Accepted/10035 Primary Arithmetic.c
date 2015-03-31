#include <stdio.h>
#include <string.h>

int main()
{

    char num1[100], num2[100];
    int i, j, len1, len2, n1, n2, sum, carry, count;

    scanf("%s %s", num1, num2);
    len1 = strlen(num1);
    len2 = strlen(num2);

    while((len1 != 1 || num1[0] != '0') || (len2 != 1 || num2[0] != '0'))
    {
        carry = count = 0;
        for (i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; --i, --j)
        {
            n1 = (int) (num1[i] - '0');
            n2 = (int) (num2[j] - '0');

            if (i < 0) n1 = 0;
            else if (j < 0) n2 = 0;

            sum = n1 + n2 + carry;

            carry = 0;

            if (sum > 9)
            {
                carry = 1;
                count++;
            }
        }

        if(count == 0) printf("No carry operation.\n");
        else if (count == 1) printf("1 carry operation.\n");
        else printf("%d carry operations.\n", count);
        scanf("%s %s", num1, num2);
        len1 = strlen(num1);
        len2 = strlen(num2);
    }

    return 0;
}
