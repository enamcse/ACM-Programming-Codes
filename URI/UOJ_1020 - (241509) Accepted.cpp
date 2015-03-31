#include <stdio.h>
#include <string.h>

int main() {

    int dias;
    int resto;

    scanf("%d", &dias);

    printf("%d ano(s)\n" ,(dias-dias%365)/365);
    if(dias%365 ==0 ) resto = dias; else resto = dias%365;
    printf("%d mes(es)\n" ,(resto-resto%30)/30);
    printf("%d dia(s)\n" ,(resto%30));


    return 0;
}
