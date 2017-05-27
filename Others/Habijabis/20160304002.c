/**
* E:\Dropbox\Code\Others\Habijabis\20160304002.c
* Created on: 2016-03-04-10.06.07, Friday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

#include <stdio.h>

int main()
{
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    FILE *f;
    f=fopen("test.txt","w");
    fprintf(f,"hello\nworld");
    fclose(f);
    char x[100];
    fopen("test.txt","r");
    while(fgets(x,100,f))
    printf ("%s",x);
    fclose(f);

//    end = clock();
//    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Time spent = "<<time_spent<<endl;

    return 0;
}
