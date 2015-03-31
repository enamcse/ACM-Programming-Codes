#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, k, len;
    char ch[1000];

    while (scanf("%s", ch) == 1)
    {
        len = strlen(ch);
        for (i = 0; i < len; ++i)
            switch (ch[i])
            {
            	case 'A':
            	case 'B':
            	case 'C':
                    ch[i] = '2';
            		break;

                case 'D':
                case 'E':
            	case 'F':
                    ch[i] = '3';
            		break;

                case 'G':
                case 'H':
            	case 'I':
                    ch[i] = '4';
            		break;

                case 'J':
                case 'K':
            	case 'L':
                    ch[i] = '5';
            		break;

                case 'M':
                case 'N':
            	case 'O':
                    ch[i] = '6';
            		break;

                case 'P':
                case 'Q':
            	case 'R':
            	case 'S':
                    ch[i] = '7';
            		break;

                case 'T':
                case 'U':
            	case 'V':
                    ch[i] = '8';
            		break;

                case 'W':
            	case 'X':
            	case 'Y':
            	case 'Z':
                    ch[i] = '9';
            		break;

            	default:
            		break;
            }
            printf("%s\n", ch);
    }
    return 0;
}
