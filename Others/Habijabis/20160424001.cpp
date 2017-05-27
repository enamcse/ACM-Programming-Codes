/**
* E:\Dropbox\Code\Others\Habijabis\20160424001.cpp
* Created on: 2016-04-24-00.35.35, Sunday
* Verdict: Not Solved
* Author: Enamul Hassan
**/
#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) (((a) ^ (b)) && ((a) ^= (b), (b) ^= (a), (a) ^= (b)))

unsigned long strlen_(char *);
char *strdup(char *s);
char *reverseString(char *, int);

int main(void)
{
    //fflush(stdout);
    char *str = (char *) malloc(1024 * sizeof (char));
    scanf("%[^\n]s", str);
    int slen = strlen_(str);
    printf("%s\n", reverseString(str, slen));
    return 0;
}

unsigned long strlen_(char *s)
{
    char *p = s;
    while (*p) p++;
    return p - s;
}

char *strdup(char *s)
{
    char *p = (char *) malloc((size_t) (strlen_(s) + 1) * sizeof (char));

    if (p) {
        char *pp = p;
        while ((*pp++ = *s++)) ;
    }
    printf("[%s]\n", p);
    return p;
}


char* reverseString(char* s, int n)
{

    char *str = strdup(s);
    char *p = str - 1;
    char *q = str + n;

    while (++p < --q) {
        swap(*p, *q);
    }

    return str;

}
