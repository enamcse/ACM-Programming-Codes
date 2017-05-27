/**
* E:\Dropbox\Code\Others\Habijabis\20160306001.c
* Created on: 2016-03-06-07.40.22, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
**/

    #include <stdio.h>

    char temp[100][100];

    int main()
    {
        FILE *file = fopen("a1.txt", "r");
        int lines = 0,i;
        while(fgets(temp[lines],100,file)) lines++;
        fclose(file);
//        file = fopen("a1.txt", "w");
//
//        for (i=0; i<lines; i++)
//            if(i!=1)fprintf(file,"%s", temp[i]);
//
//
//        fclose(file);

        return 0;
    }
