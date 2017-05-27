/**
* E:\Dropbox\Code\Others\Habijabis\20160301001.c
* Created on: 2016-03-01-00.37.59, Tuesday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <stdio.h>

struct student
{
	char name[24];
	char dept_name[5];
	float cgpa;
	long long id_no;
};

int main(void) {
	printf("%d %d", sizeof(long long), sizeof(struct student));
	return 0;
}
