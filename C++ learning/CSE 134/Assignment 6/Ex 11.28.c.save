#include <stdio.h>

typedef struct
{
    int month;
    int day;
    int year;
} date;

typedef struct
{
    char name[80];
    char street[80];
    char city[80];
    int acct_no;
    char acct_type;
    float oldbalance;
    float newbalance;
    float payment;
    date lastpayment;
} record;

record readinput(int i);
void writeoutput (record customer);

int main()
{
    int i, n;
    record customer[100];

    printf("CUSTOMER BILLING SYSTEM\n\n");
    printf("How many customers are there? ");
    scanf("%d", &n);

    for (i = 0; i < n; ++i)
    {
        customer[i] = readinput(i);

        if (customer[i].payment > 0)
            customer[i].acct_type =
                (customer[i].payment < 0.1 * customer[i].oldbalance) ? 'O' : 'C';
        else
            customer[i].acct_type =
                (customer[i].oldbalance > 0) ? 'D' : 'C';

        customer[i].newbalance = customer[i].oldbalance - customer[i].payment;
    }

    printf("\n\n\n");
    for (i=0; i<n; ++i)
        writeoutput(customer[i]);
    return 0;
}

record readinput(int i)
{
    record customer;
    printf("\nCustomer no. %d\n", i + 1);
    printf("    Name: ");
    scanf(" %[^\n]", customer.name);
    printf("    Street: ");
    scanf(" %[^\n]", customer.street);
    printf("    City: ");
    scanf(" %[^\n]", customer.city);
    printf("    Account number: ");
    scanf(" %d", &customer.acct_no);
    printf("    Previous balance: ");
    scanf(" %f", &customer.oldbalance);
    printf("    Current payment: ");
    scanf(" %f", &customer.payment);
    printf("    Payment date (mm/dd/yyyy): ");
    scanf("%d/%d/%d",   &customer.lastpayment.month,
                        &customer.lastpayment.day,
                        &customer.lastpayment.year);
    return (customer);
}

void writeoutput(record customer)
{
    printf("    Name:   %s", customer.name);
    printf("    Account number: %d\n", customer.acct_no);
    printf("    Street: %s\n", customer.street);
    printf("    City: %s\n\n", customer.city);
    printf("    Old balance: %7.2f", customer.oldbalance);
    printf("    Current payment: %7.2f", customer.payment);
    printf("    New balance: %7.2f\n\n", customer.newbalance);
    printf("    Account status: ");

    switch (customer.acct_type)
    {
    case 'C':
        printf("CURRENT\n\n");
        break;
    case 'O':
        printf("OVERDUE\n\n");
        break;
    case 'D':
        printf("DELIQUENT\n\n");
        break;
    default:
        printf("ERROR\n\n");
    }
    return;
}
