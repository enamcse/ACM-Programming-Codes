/*
A file, named "birthday.txt", should exist in the containing folder
of the program, where everybody's name and birthday should be written
in this format "NAME dd/mm/yyyy" in every line.
*/
#include <stdio.h>
#include <string.h>

int first_day(int dd, int mm, int yyyy);
void calender (int yyyy, int day);


char month_name[12][10] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY",
                           "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER",
                           "NOVEMBER", "DECEMBER"
                          };

char day_name[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main()
{
    int dd, mm, yyyy, day, i, flag, info_day, info_month, info_yr;
    char name[20], info_name[20], c;
    /*FILE *file1;

    printf("Please write the name of a person (as in file) : ");
    while (scanf("%s", name) == 1)
    {
        file1 = fopen("birthday.txt", "r");
        flag = 1;
        for (i = 0;  !feof(file1); i++)
        {
            fscanf(file1, " %s %d/%d/%d", info_name, &info_day,
                   &info_month, &info_yr);
            if(strcmp(info_name, name) == 0)
            {
                dd = info_day;
                mm = info_month;
                yyyy = info_yr;
                flag = 0;
                break;
            }
        }
        if (flag) printf("\n\nName not found in the list. Try again : ");
        else
        {*/
            printf("Happy Birthday Dosto....\nHappy Birthday DR ENGG. S.M. ZOBAED SAKIB\n\
Professor, Dept. of ***, IUT\n\nDosto, 2mar birth year ta leikha enter maro(e.g.:1992)");
            scanf("%d", &yyyy);
            dd = 18;
            mm = 6;
            day = first_day(dd, mm, yyyy);
            calender(yyyy,day);

            printf("\n\nVagina, aita amar pokkho theika 2mar jonmo diner upohar,\n\
Ai code tar mul kam ashole file theika kisu mainsher birthday input neya. tarpor codeta \n\
run korle oi namgulo theika jodi tumi karo nam lekho, taile she jei bosor jonmaise, sei\n\
bosorer calanderta dekhaibo. jehetu codeta shudhu 2mar leiga utshorgo kora, tai aikhane \n\
main ar vitore sob akam gulo comment akare nia gesi, ar ai koyda line baraisi 2mar laiga\n\
kintu vagina, 2mar jonmoshal ta vuilagesi, tai tumar jonmoshalta chaisi.\n\
valo thako janu, %c you...\nI %c you so much vagina...\nFormal kotha ar barailam na\n",3,3);
            /*printf("\n\nPlease write the name of a person (as in file) : ");
        }
        fclose(file1);
    }*/

    return 0;
}

int first_day(int d, int m, int y)
{
    int i, j, year = 2012, month = 1, day = 1, date = 1, highest_day;

    if (y == year) return 1;
    else if (year > y)
    {
        for (i = 0; year != y || month != 1; i++)
        {
            --month;
            if (month == 0)
            {
                month = 12;
                --year;
            }

            switch (month)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                highest_day = 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                highest_day = 30;
                break;
            case 2:
                if(year%4 == 0) highest_day = 29;
                else highest_day = 28;
                break;
            }

            for (j = highest_day; j != 0; j--)
            {
                --day;
                if (day == 0) day = 7;
            }
        }
        return day;
    }
    else
    {
        for (i = 0; year != y || month != 1; i++)
        {
            switch (month)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                highest_day = 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                highest_day = 30;
                break;
            case 2:
                if(year%4 == 0) highest_day = 29;
                else highest_day = 28;
                break;
            }

            for (j = highest_day; j != 0; j--)
            {
                --day;
                if (day == 0) day = 7;
            }

            ++month;
            if (month == 13)
            {
                month = 1;
                ++year;
            }
        }
        ++day;
        if (day == 8) day = 1;
        return day;
    }
}

void calender (int yyyy, int day)
{
    int month = 1, date = 1, i, j, space, highest_day;

    printf("     CALENDER OF THE YEAR %5d\n", yyyy);

    for (i = 0; i < 12; i++)
    {
        printf("\t%12s\n", month_name[i]);

        for (j = 0; j < 35; j++) printf("-");
        printf("\n");

        for (j = 0; j < 7; j++)
            printf("%5s", day_name[j]);
        printf("\n");

        space = day - 1;
        for (j = space * 5; j > 0; j--)
            printf("%c", 32);

        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            highest_day = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            highest_day = 30;
            break;
        case 2:
            if(yyyy%4 == 0) highest_day = 29;
            else highest_day = 28;
        }

        for (j = 1; j <= highest_day; j++)
        {
            printf("%5d", j);
            ++day;
            if (day == 8)
            {
                printf("\n");
                day = 1;
            }
        }

        printf("\n\n");

        ++month;
    }
}
