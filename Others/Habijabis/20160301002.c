/**
* E:\Dropbox\Code\Others\Habijabis\20160301002.c
* Created on: 2016-03-01-14.05.54, Tuesday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <stdio.h>

int main()
{
    double loan_amount, interest_rate, number_of_years,total_amount,monthly_amount;
    printf("Enter the loan amount: ");
    scanf("%lf", &loan_amount);
    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);
    printf("Number of years: ");
    scanf("%lf", &number_of_years);
    total_amount= loan_amount + loan_amount * interest_rate * 5/ 100;
    monthly_amount = total_amount/(number_of_years * 12);
    printf("Total amount:%0.2lf\n", total_amount);
    printf("Monthly amount:%0.2lf\n", monthly_amount);

    return 0;
}
