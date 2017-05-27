/**
* E:\Dropbox\Code\Others\Habijabis\20160304001.c
* Created on: 2016-03-04-09.53.22, Friday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <stdio.h>
struct {
    char *name;
    int age;
} rokib, niton = {"Shaon", 21};

const iAmConst=25;
int iAmNotConst;
int main()
{
    rokib = niton;

    /// *(rokib.name+2) = 'a';
    /// iAmConst = 21;

    rokib.name = strdup( "Rokib");
    iAmNotConst = iAmConst;
//    strcpy(rokib.name, "Rokib");
    rokib.age = 22;


    *(rokib.name+2) = 'a';
    iAmNotConst = 21;

    printf("%s %d\n", niton.name, niton.age);
    printf("%s %d\n", rokib.name, rokib.age);

    return 0;
}
