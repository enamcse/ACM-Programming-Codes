#include <stdio.h>
#include <math.h>

typedef union
{
    float fexp;
    int nexp;
} nvals;

typedef struct
{
    float x;
    char flag;

    nvals exp;
} values;

float power(values a);

int main()
{
    values a;
    int i;
    float n, y;

    printf("y = x^n\n\nEnter a value for x: ");
    while(scanf("%f", &a.x) == 1)
    {
        printf("Enter a value for n: ");
        scanf("%f", &n);

        i = (int) n;
        a.flag = (i == n) ? 'i' : 'f';
        if (a.flag == 'i')
            a.exp.nexp = i;
        else
            a.exp.fexp = n;

        if (a.flag == 'f' && a.x <= 0.0)
        {
            printf("\nERROR - Cannot raise a non positive number to a ");
            printf("floating-point power");
        }
        else
        {
            y = power(a);
            printf("\n y = %.4f", y);
        }
        printf("\n\nEnter a value for x: ");
    }
    return 0;
}

float power(values a)
{
    int i;
    float y = a.x;

    if (a.flag == 'i')
    {
        if (a.exp.nexp == 0)
            y = 1.0;
        else
        {
            for (i = 1; i < abs(a.exp.nexp); ++i)
                y *= a.x;
            if (a.exp.nexp < 0)
                y = 1./y;
        }
    }
    else    y = exp(a.exp.fexp * log(a.x));

    return y;
}
