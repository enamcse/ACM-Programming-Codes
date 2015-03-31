#include <stdio.h>
#include <string.h>

int main()
{
    int i, times, n, caseno=1,len;
    char line[105];

    scanf("%d", &n);
    getchar();

    while(n--)
    {
        times=0;
        gets(line);
        len = strlen(line);
        for (i = 0; i < len; i++)
            if (line[i] == 'a' || line[i] == 'd' || line[i] == 'g' || line[i] == 'j' ||
               line[i] == 'm' || line[i] == 'p' || line[i] == 't' || line[i] == 'w' ||
               line[i] == ' ') times++;
            else if (line[i] == 'b' || line[i] == 'e' || line[i] == 'h' ||
                     line[i] == 'k' || line[i] == 'n' || line[i] == 'q' ||
                     line[i] == 'u' || line[i] == 'x') times+=2;
            else if (line[i] == 'c' || line[i] == 'f' || line[i] == 'i' ||
                     line[i] == 'l' || line[i] == 'o' || line[i] == 'r' ||
                     line[i] == 'v' || line[i] == 'y') times+=3;
            else if(line[i] == 's' || line[i] == 'z') times+=4;

        printf("Case #%d: %d\n", caseno++, times);
    }

    return 0;
}
/*


#include <stdio.h>
#include <string.h>

int main()
{
    int i, times, n, caseno=1,len;
    char line[105];

    scanf("%d", &n);
    getchar();
    while(n--)
    {
        times=0;
        gets(line);
        len = strlen(line);
        for (i = 0; i < len; i++)
            switch (line[i])
            {
            case 'a':
            case 'd':
            case 'g':
            case 'j':
            case 'm':
            case 'p':
            case 't':
            case 'w':
            case ' ':
                times++;
                break;

            case 'b':
            case 'e':
            case 'h':
            case 'k':
            case 'n':
            case 'q':
            case 'u':
            case 'x':
                times+=2;
                break;

            case 'c':
            case 'f':
            case 'i':
            case 'l':
            case 'o':
            case 'r':
            case 'v':
            case 'y':
                times+=3;
                break;


            case 's':
            case 'z':
                times+=4;
                break;
            }


        printf("Case #%d: %d\n", caseno++, times);
    }

    return 0;
}
*/
