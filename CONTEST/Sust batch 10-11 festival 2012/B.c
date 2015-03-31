#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int i, j, len, count, java, C;
    char input[101], output[200], error[] = "Error!";

    while(gets(input))
    {
        count = 0;
        java = 0;
        C = 0;
        len = strlen(input);
        if(input[0] == '_' || input[len-1]== '_' ||(input[0] >= 'A' && input[0] <= 'Z'))
        {
            java = 1;
            C = 1;
        }
        else
            for(i = 0; i < len; ++i)
            {
                if(input[i] == '_' && java == 0)
                {
                    C = 1;
                    ++i;
                    if(input[i] >= 'A' && input[i] <= 'Z')
                    {
                        java=1;
                        break;
                    }
                    else if(input[i] == '_')
                    {
                        java=1;
                        break;
                    }
                    else
                        output[count++] = toupper(input[i]);
                }
                else if(input[i] >= 'A' && input[i] <= 'Z' && C == 0)
                {
                    java = 1;
                    output[count++] = '_';
                    output[count++] = tolower(input[i]);
                }
                else if(input[i] == '_' && java == 1) C = 1;
                else if(input[i] >= 'A' && input[i] <= 'Z' && C == 1) java = 1;
                else
                {
                    output[count++] = input[i];
                }

                if(java == 1 && C == 1) break;

            }
        output[count] = '\0';
        if(java && C) puts(error);
        else puts(output);
    }
}
