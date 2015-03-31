#include <stdio.h>
#include <string.h>

#define choose printf("\n\nEnter your choice number from below:\n \
            1 - To see anyone\'s birthday.\n \
            2 - To see whose birthday in a month.\n \
            3 - To END.\n\n \
            Your choice : ");

struct date
{
    char name[80];
    int month;
    int day;
    int year;
};

static struct date birthday[] = {"Amy", 12, 30, 73,
    "Gail", 5, 13, 66,
    "Marc", 7, 15, 72,
    "Marla", 11, 29, 70,
    "Megan", 2, 4, 77,
    "Sharon", 12, 29, 63,
    "Susan", 4, 12, 69
};

int main()
{
    int i, flag = 0, choice, month;
    char name[80];

    choose

    while(scanf("%d", &choice))
    {
        switch (choice)
        {
        case 1:
            printf("Write the person\'s name: ");
            scanf("%s", name);
            for (i = 0; i < 7; ++i)
                if(strcmp(birthday[i].name, name) == 0)
                    printf("Name : %s\nBirthday (dd/mm/yy) : %d/%d/%d\n",
                           birthday[i].name, birthday[i].day,
                           birthday[i].month,  birthday[i].year);
            break;

        case 2:
            printf("Write the month number: ");
            scanf("%d", &month);
            for (i = 0; i < 7; ++i)
                if(birthday[i].month == month)
                    printf("Name : %s\nBirthday (dd/mm/yy) : %d/%d/%d\n",
                           birthday[i].name, birthday[i].day,
                           birthday[i].month,  birthday[i].year);
            break;

        case 3:
            flag = 1;
            break;

        default:
            printf("ERROR - chosen an invalid number. Try again.\n");
        }
        if(flag) break;
        choose
    }

    return 0;
}
