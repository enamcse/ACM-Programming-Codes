/**
* H:\Dropbox\Code\Codeforces\test.cpp
* Created on: 2015-02-28-19.55.43, Saturday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include<stdio.h>
char *program="#include<stdio.h>%cchar *program=%c%s%c;%cvoid main()%c{%cprintf(program,10,34,program,34,10,10,10,10);%c}";

int main()

{
printf(program,10,34,program,34,10,10,10,10);
return 0;
}
