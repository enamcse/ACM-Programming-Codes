#include <stdio.h>

int main()
{
    int x, y12, sum_1, _temperature, 4th, "x", order-no, error flag;
    /*last four identifiers are invalid due to:
        4th-->          identifiers cant start with number.
        "x"-->          invalid character " for identifier.
        order-no-->     '-' sign cant be used in identifier.
        error flag-->   space cant be used in identifier.
    */

    scanf("%d %d", &x, &y12);

    sum_1 = x + y12;

    printf("%d + %d = %d\n", x, y12, sum_1);

    _temperature = 25;

    printf("Calculated in temp. %d degree celcious\n", _temperature);

    "x" = sum_1 / _temperature;

    4th = x * y12;

    order-no = 4th - "x";

    error flag = order-no * order-no;

    printf("Answer 1 is : %d\nAnswer 2 is : %d\nAnswer 3 is : %d\nAnswer 4 is : %d\nSEE YOU!\n", "x", 4th, order-no, error flag);

    return 0;
}
