#include <stdio.h>
#include <ctype.h>

void scan_line (char line[], int *pv, int *pc, int *pd, int *pw, int *po);

int main()
{
   char line[80];
   int vowels = 0;
   int consonants = 0;
   int digits = 0;
   int whitespc = 0;
   int other = 0;

    printf("Enter a line of text below\n");
    scanf("%[^\n]", line);

    scan_line(line, &vowels, &consonants, &digits, &whitespc, &other);

    printf("\nNo. of vowels: %d", vowels);
    printf("\nNo. of consonants: %d", consonants);
    printf("\nNo. of digits: %d", digits);
    printf("\nNo. of whitespace characters: %d", whitespc);
    printf("\nNo. of other: %d", other);

    return 0;
}

void scan_line (char line[], int *pv, int *pc, int *pd, int *pw, int *po)
{
    char c;
    int count = 0;
    while ((c = toupper(line[count])) != '\0')
    {
        if (c == 'A' || c == 'I' || c == 'O' || c == 'E' || c == 'U')
            ++ *pv;
        else if (c >= 'A' && c <= 'Z')
                ++ *pc;
            else if (c >= '0' && c <= '9')
                    ++ *pd;
                else if (c == ' ' || c == '\t')
                        ++ *pw;
                    else
                        ++ *po;

        ++count;
    }
    return;
}
