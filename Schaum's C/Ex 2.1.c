#include <stdio.h>

int main()
{
    int x, y12, sum_1, _temperature, names, area, tax_rate, TABLE;

    scanf("%d %d", &x, &y12);

    sum_1 = x + y12;

    printf("%d + %d = %d\n", x, y12, sum_1);

    _temperature = 25;

    printf("Calculated in temp. %d degree celcious\n", _temperature);

    names = sum_1 / _temperature;

    area = x * y12;

    tax_rate = area - names;

    TABLE = tax_rate * tax_rate;

    printf("Answer 1 is : %d\nAnswer 2 is : %d\nAnswer 3 is : %d\nAnswer 4 is : %d\nSEE YOU!\n", names, area, tax_rate, TABLE);

    return 0;
}
