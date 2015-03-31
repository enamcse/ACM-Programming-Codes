#include <stdio.h>

void calculate(long int dd, long int mm, long int yyyy, long int day);
long int month_day(long int num, long int year);
long int year_day(long int year);

long int main()
{
    long int mm, dd, yyyy;
    long int day;

    scanf("%ld %ld %ld %ld", &day, &dd, &mm, &yyyy);

    while(day != 0 || dd != 0 || mm != 0 || yyyy != 0)
    {
        calculate(dd,mm,yyyy,day);
        scanf("%ld %ld %ld %ld", &day, &dd, &mm, &yyyy);
    }
    return 0;
}

void calculate(long int dd, long int mm, long int yyyy, long int day)
{
    long int dayz;
    if(dd >= 1 && mm > 2) dayz = year_day(yyyy+1);
    else dayz = year_day(yyyy);
    while(day - dayz >= 0)
    {
        day-=dayz;
        yyyy++;
        if(dd >= 1 && mm > 2) dayz = year_day(yyyy+1);
        else dayz = year_day(yyyy);
    }
    dayz = month_day(mm,yyyy);
    while(day - dayz >= 0)
    {
        day-=dayz;
        mm++;
        if(mm == 13)
        {
            mm = 1;
            yyyy++;
        }
        dayz = month_day(mm,yyyy);
    }
    dd += day;
    while(dd > dayz)
    {
        dd -= dayz;
        mm++;
        if(mm == 13)
        {
            mm = 1;
            yyyy++;
        }
        dayz = month_day(mm,yyyy);
    }
    printf("%ld %ld %ld\n", dd, mm, yyyy);
    return;
}

long int month_day(long int num, long int year)
{
    switch(num)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;

    case 2:
        if(year%4==0 && year%100!=0) return 29;
        else if (year%4==0 && year%400==0) return 29;
        else return 28;
    }

}

long int year_day(long int year)
{
    if(year%4==0 && year%100!=0) return 366;
    else if (year%4==0 && year%400==0) return 366;
    else return 365;
}
