#include <Windows.h>
#include <stdio.h>

int main()
{
    SYSTEMTIME str_t;
    while(getchar())
    {
        GetSystemTime(&str_t);

        printf("Year:%d\nMonth:%d\nDate:%d\nHour:%d\nMin:%d\nSecond:% d\n"
               ,str_t.wYear,str_t.wMonth,str_t.wDay
               ,str_t.wHour,str_t.wMinute,str_t.wSecond);
    }
    return 0;
}

/**
https://www.thegeekstuff.com/2012/08/c-linked-list-example/
https://www.codingunit.com/c-tutorial-how-to-use-time-and-date-in-c
http://www.tutorialspoint.com/c_standard_library/c_function_rand.htm
https://en.wikibooks.org/wiki/A_Little_C_Primer/C_String_Function_Library

make file:
http://mrbook.org/tutorials/make/
*/
