/**
* E:\Dropbox\Code\Others\Habijabis\20160307001.c
* Created on: 2016-03-07-12.46.21, Monday
* Verdict: Not Solved
* Author: Enamul Hassan
**/
#include <stdio.h>
struct student
{
    char name[22];
    char dept[5];
    float cgpa;
    double id;

}shaon;
int main()
{
    printf("%d\n", sizeof(shaon));
    printf("%d", sizeof(shaon.id));
    return 0;
}
