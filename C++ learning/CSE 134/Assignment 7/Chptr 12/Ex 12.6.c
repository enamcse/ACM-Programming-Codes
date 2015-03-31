#include <stdio.h>
#include <string.h>

#define TRUE 1

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

record readfile(record customer);
record update(record customer);
void writefile(record customer);

FILE *ptold,*ptnew;
int month, day, year;

int main()
{
    int flag = TRUE;
    record customer;
    if((ptold = fopen("record.old", "r")) == NULL)
        printf("\n ERROR - Cannot open the designed read file.\n");
    else
    {
        ptnew = fopen("records.new", "w");

        printf("CUSTOMER BILLING SYSTEM - UPDATE\n\n");
        printf("Please enter today's date (mm/dd/yy): ");
        scanf("%d/%d/%d", &month, &day, &year);

        while(flag)
        {
            fscanf(ptold, " %[^\n]", customer.name);
            fprintf(ptnew, "\n%s\n", customer.name);

            if(strcmp(customer.name,"END") == 0) break;

            customer = readfile(customer);
            customer = update(customer);

            writefile(customer);
        }
        fclose(ptold);
        fclose(ptnew);
    }
}

record readfile(record customer)
{
    fscanf(ptold, "%s\n", customer.street);
    fscanf(ptold, "%s\n", customer.city);
    fscanf(ptold, "%d\n", customer.acct_no);
    fscanf(ptold, "%c\n", customer.acct_type);
    fscanf(ptold, "%.2f\n", customer.oldbalance);
    fscanf(ptold, "%.2f\n", customer.newbalance);
    fscanf(ptold, "%.2f\n", customer.payment);
    fscanf(ptold, "%d/%d/%d\n", customer.lastpayment.month,
           customer.lastpayment.day,
           customer.lastpayment.year);
    return(customer);
}

record update(record customer)
{
    printf("\n\nName:  %s", customer.name);
    printf("    Account number: %d\n", customer.acct_no);
    printf("\nOld balance: %7.2f", customer.oldbalance);
    printf("   Current payment: ");
    scanf("%f", &customer.payment);

    if(customer.payment > 0)
    {
        customer.lastpayment.month = month;
        customer.lastpayment.day = day;
        customer.lastpayment.year = year;
        customer.acct_type = (customer.payment<0.1 * customer.oldbalance)?'O':'C';

    }
    else
        customer.acct_type=(customer.oldbalance>0)?'D':'C';
    printf("New balance: %7.2f", customer.newbalance);

    printf("  Account status: ");
    switch(customer.acct_type)
    {
    case 'C':
        printf("CURRENT\n");
        break;
    case 'O':
        printf("OVERDUE\n");
        break;
    case 'D':
        printf("DELINQUENT\n");
        break;
    default:
        printf("ERROR\n");
    }
    return(customer);
}

void writefile(record customer)
{
    fprintf(ptnew, "%s\n", customer.street);
    fprintf(ptnew, "%s\n", customer.city);
    fprintf(ptnew, "%d\n", customer.acct_no);
    fprintf(ptnew, "%c\n", customer.acct_type);
    fprintf(ptnew, "%.2f\n", customer.oldbalance);
    fprintf(ptnew, "%.2f\n", customer.newbalance);
    fprintf(ptnew, "%.2f\n", customer.payment);
    fprintf(ptnew, "%d/%d/%d\n", customer.lastpayment.month,
            customer.lastpayment.day,
            customer.lastpayment.year);
    return;

}
